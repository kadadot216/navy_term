/*
** EPITECH PROJECT, 2018
** running.c
** File description:
** Game running related functions
*/

#include "my.h"
#include "types.h"
#include "messages.h"
#include "connect.h"
#include "action_queries.h"
#include "game.h"

extern com_interface_t	iface;

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
			game = send_attack_response(&prompt, game, iface.epid);
		}
		check_for_winner(turn, game);
		turn++;
	}
	display_winner_msg(game->status);
	return (1);
}
