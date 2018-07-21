/*
** EPITECH PROJECT, 2018
** running.c
** File description:
** Game running related functions
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#include "my.h"
#include "types.h"
#include "game.h"

#define	SLEEP	(5000000)

extern com_interface_t	iface;

void	receive_bit_unsafe(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (iface.bitval == 16) {
		iface.bitval = 1;
	}
	if (sig == SIGUSR2) {
		iface.query += iface.bitval;
		iface.bitval *= 2;
	} else if (sig == SIGUSR1) {
		iface.bitval *= 2;
	}
}

void	get_p2pid(int sig, siginfo_t *info, void *context)
{
	(void)context;
	iface.epid = info->si_pid;
}

void	receive_bit(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (iface.bitval > 16) {
		iface.bitval = 1;
	}
	if (sig == SIGUSR2 && (iface.epid == info->si_pid)) {
		iface.query += iface.bitval;
		iface.bitval *= 2;
	} else if (sig == SIGUSR1 && (iface.epid == info->si_pid)) {
		iface.bitval *= 2;
	}
}

int	receive_query(int value)
{
	int	received = 0;
	int	tstat = 0;
	
	while (iface.bitval < 16) {
		tstat = usleep(SLEEP);
		if (tstat != -1) {
			return (0);
		}
	}
	received = iface.query;
	iface.query = 0;
	return (received);
}

int	receive_connection_query(void)
{
	int	query = 0;
	struct sigaction	epid_handle;
	struct sigaction	unsafe_sig;

	unsafe_sig.sa_flags = SA_SIGINFO;
	unsafe_sig.sa_handler = &receive_bit_unsafe;
	epid_handle.sa_flags = SA_SIGINFO;
	epid_handle.sa_handler = &get_p2pid;
	sigaction(SIGUSR1, &unsafe_sig, NULL);
	sigaction(SIGUSR2, &unsafe_sig, NULL);
	query = receive_query(15);
	if (query == 15) {
		sigaction(SIGUSR1, &epid_handle, NULL);
		if (usleep(SLEEP) != -1) {
			return (0);
		}
		sigaction(SIGUSR1, &iface.sig, NULL);
		return (1);
	}
	return (0);
}


void	send_query(int value, pid_t epid)
{
	int	bitval = 8;

	while (value > 0 && value < 15) {
		if (value >= bitval) {
			kill(epid, SIGUSR1);
			value -= bitval;
			bitval /= 2;
			my_put_nbr(1);
		}
		else if (value < bitval) {
			kill(epid, SIGUSR2);
			bitval /= 2;
			my_put_nbr(0);
		}
		usleep(10);
	}
	my_putchar('\n');
}

player_t	change_turn(player_t turn)
{
	return ((turn + 1) % 2);
}

void	check_for_winner(player_t turn, navy_game_t *game)
{
	if (game->total_hits[turn] == 0) {
		game->status = turn + 2;
	}
}

void	display_winner_msg(game_status_t status)
{
	if (status == P1_WON) {
		my_putstr_fd(1, "I won");
	} else if (status == P2_WON) {
		my_putstr_fd(1, "Enemy won");
	}
}

int	prompt_valid_attack(char const *prompt)
{
	if (my_strlen(prompt) != 3) {
		my_putstr_fd(2, "wrong position\n");
		return (0);
	} else if (!((prompt[0] >= 'A' && prompt[0] <= 'H') && (prompt[1] >= '1' && prompt[1] <= '8'))) {
		my_putstr_fd(2, "wrong position\n");
		return (0);
	}
	return (1);
}

int	prompt_instruction(parser_t *parser)
{
	char	prompt[1000] = {0};

	my_putstr_fd(1, "attack: ");
	while (!(read(0, prompt, 1000)) || !(prompt_valid_attack(prompt))) {
		my_putstr_fd(1, "attack: ");
	}
	parser->x = prompt[0] - 'A';
	parser->y = prompt[1] - '1';
	return (1);
}

void	display_attack_msg(parser_t *p)
{
	my_putchar(p->x + 'A');
	my_putchar(p->y + '1');
	my_putstr_fd(1, ": ");
}

int	dispatch_instruction(parser_t *p, board_t **board)
{
	display_attack_msg(p);
	if (board[p->y][p->x] == NONE) {
		board[p->y][p->x] = MISSED;
		my_putstr_fd(1, "missed\n\n");
		return (0);
	} else if (board[p->y][p->x] >= L2 && board[p->y][p->x] <= L5) {
		board[p->y][p->x] = HIT;
		my_putstr_fd(1, "hit\n\n");
		return (1);
	}
	return (0);
}

void	display_game(navy_game_t *game)
{
	my_putstr_fd(1, "my positions:\n");
	display_board(game->boards[P1]);
	my_putstr_fd(1, "enemy's positions:\n");
	display_board(game->boards[P2]);
	my_putstr_fd(1, "\n");
}


int	wait_for_connection(void)
{
	int	query = 0;

	my_putstr_fd(1, "my pid: ");
	my_put_nbr(getpid());
	my_putchar('\n');
	iface.connected = receive_connection_query();

	if (iface.connected == 0) {
		my_putstr_fd(2, "\nConnexion timed out...\n");
		return (0);
	} else if (iface.connected == 1) {
		my_putstr_fd(1, "\nenemy connected\n");
		return (1);
	}
	my_putstr_fd(1, "Wrond PID or unexcpected signal");
	return (0);
}

int	send_connection_sig(void)
{
	int	response = 0;

	my_putstr_fd(1, "Waiting for P1 response\n");
	send_query(15, iface.epid);
	usleep(30);
	kill(SIGUSR1, iface.epid);
	my_put_nbr(iface.epid);
	my_putchar('\n');
	response = receive_query(15);
	if (response == 15) {
		return (0);
	}
	my_putstr_fd(1, "successfully connected\n");
	return (1);
}

int	play_game(navy_game_t *game)
{
	player_t	turn = P1;
	parser_t	prompt;
	
	if (game->me == P1 && !wait_for_connection()) {
		return (0);
	} else if (game->me == P2 && !send_connection_sig()) {
		return (0);
	}
	while (game->status == RUNNING && iface.connected)	{
		display_game(game);
		prompt_instruction(&prompt);
		game->total_hits[turn] -= dispatch_instruction(&prompt, game->boards[turn]);
		check_for_winner(turn, game);
		turn = change_turn(turn);
	}
	display_winner_msg(game->status);
	return (1);
}
