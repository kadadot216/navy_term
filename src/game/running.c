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

#define	SLEEP	(50000000)

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

int	receive_query(void)
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

	iface.sig.sa_sigaction = &receive_bit_unsafe;
	sigaction(SIGUSR1, &iface.sig, NULL);
	sigaction(SIGUSR2, &iface.sig, NULL);
	query = receive_query();
	if (query == 15) {
		iface.sig.sa_sigaction = &get_p2pid;
		sigaction(SIGUSR1, &iface.sig, NULL);
		if (usleep(SLEEP) != -1) {
			return (0);
		}
		iface.sig.sa_sigaction = &receive_bit;
		sigaction(SIGUSR1, &iface.sig, NULL);
		sigaction(SIGUSR2, &iface.sig, NULL);
		return (1);
	}
	return (0);
}


void	send_query(int value, pid_t epid)
{
	int	bitval = 8;
	int	idx = 3;
	int	sigword[4] = {0};

	while (value > 0 && value < 16 && idx >= 0) {
		if (value >= bitval) {
			sigword[idx] = SIGUSR2;
			value -= bitval;
			bitval /= 2;
		}
		else if (value < bitval) {
			sigword[idx] = SIGUSR1;
			bitval /= 2;
		}
		idx--;
	}
	idx = 0;
	while (idx < 4) {
		kill(epid, sigword[idx]);
		idx++;
		usleep(10);
	}
}

void	check_for_winner(player_t turn, navy_game_t *game)
{
	if (game->total_hits[(turn % 2)] == 0) {
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
	display_board(game->boards[0]);
	my_putstr_fd(1, "\nenemy's positions:\n");
	display_board(game->boards[1]);
	my_putstr_fd(1, "\n");
}


int	wait_for_connection(void)
{
	int	query = 0;

	my_putstr_fd(1, "my pid: ");
	my_put_nbr(getpid());
	my_putchar('\n');
	my_putstr_fd(1, "waiting for enemy connection...\n");
	iface.connected = receive_connection_query();

	if (iface.connected == 0) {
		my_putstr_fd(2, "\nconnexion timed out...\n");
		return (0);
	} else if (iface.connected == 1) {
		my_putstr_fd(1, "\nenemy connected\n");
		return (1);
	}
	my_putstr_fd(2, "wrong PID or unexcpected signal\n");
	return (0);
}

int	send_connection_sig(void)
{
	int	response = 0;

	my_putstr_fd(1, "my pid: ");
	my_put_nbr(getpid());
	my_putchar('\n');
	send_query(15, iface.epid);
	usleep(30);
	kill(iface.epid, SIGUSR1);
	my_putstr_fd(1, "successfully connected\n");
	return (1);
}

void	send_attack_query(parser_t *prompt, pid_t epid)
{
	int	pos_x = (prompt->x + 1);
	int	pos_y = (prompt->y + 1);

	send_query(pos_x, epid);
	usleep(10);
	send_query(pos_y, epid);
	usleep(10);
}

void	dispatch_response_query(navy_game_t *game, parser_t *prompt)
{
	int	hit = receive_query(); 	

	display_attack_msg(prompt);
	if (hit == 2) {
		game->boards[1][prompt->y][prompt->x] = HIT;
		game->total_hits[1]--;
		my_putstr_fd(1, "hit\n\n");
	} else if (hit == 1) {
		game->boards[1][prompt->y][prompt->x] = MISSED;
		my_putstr_fd(1, "missed\n\n");
	}
}

parser_t	receive_attack_query(void)
{
	parser_t	query = {0, 0};

	my_putstr_fd(1, "\nwaiting for enemy's attack...\n");
	query.x = receive_query() - 1; 
	query.y = receive_query() - 1; 
	return (query);
}

void	send_attack_response(parser_t *p, navy_game_t *game, pid_t epid)
{
	board_t	*position = &game->boards[0][p->y][p->x];

	display_attack_msg(p);
	if (*position >= L2 && *position <= L5)	 {
		game->boards[0][p->y][p->x] = HIT;
		game->total_hits[0]--;
		send_query(2, epid);
		my_putstr_fd(1, "hit\n\n");
	} else if (*position == NONE) {
		*position = MISSED;
		send_query(1, epid);
		my_putstr_fd(1, "missed\n\n");
	}
}

int	play_game(navy_game_t *game)
{
	player_t	turn = P1;
	parser_t	prompt = {0, 0};
	
	if (game->me == P1 && !wait_for_connection()) {
		return (0);
	} else if (game->me == P2 && !send_connection_sig()) {
		return (0);
	}
	while (game->status == RUNNING && iface.connected)	{
		display_game(game);
		if (turn % 2 == game->me) {
			prompt_instruction(&prompt);
			send_attack_query(&prompt, iface.epid);
			dispatch_response_query(game, &prompt);
		} else {
			prompt = receive_attack_query();
			send_attack_response(&prompt, game, iface.epid);
		}
		check_for_winner(turn, game);
		turn++;
	}
	display_winner_msg(game->status);
	return (1);
}
