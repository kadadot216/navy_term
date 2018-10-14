/*
** EPITECH PROJECT, 2018
** turn.c
** File description:
** Turn functions
*/

#include "main.h"

void	turn_attack(char *prompt)
{
	int	hit = -1;
	char	*hit_msg[] = {
		"miss",
		"hit"
	};

	prompt_attack(prompt);
	interface_act_compose_attack(prompt);
	interface_act_send_query();
	hit = interface_act_receive_response();
	my_putstr_fd(1, prompt);
	my_putstr_fd(1, ": ");
	my_putstr_fd(1, hit_msg[hit]);
	my_putstr_fd(1, "\n");
}

game_t	*update_board(int index, game_t *game)
{
	int	hit = -1;

	if (cell_is_boat(&game->board[index])) {
		game->board[index] = CELL_HIT;
		hit = 1;
	}
	else {
		game->board[index] = CELL_MISS;
		hit = 0;
	}
	interface_act_send_response(hit);
	return (game);
}

void	turn_wait(game_t *game)
{
	int	status = 0;
	int	index = -1;
	char	coords[3] = {'\0'};

	my_putstr_fd(1, "waiting for ennemy's attack...\n");
	status = interface_act_receive_coords();
	if (status == 1) {
		index = interface_act_retrieve_coords();
		get_coords_from_idx(coords, index);
		game = update_board(index, game);
	}
}

void	play_turn(game_t *game, char *prompt)
{
	if (game->role == ROLE_PLAY) {
		turn_attack(prompt);
	} 
	if (game->role == ROLE_WAIT) {
		turn_wait(game);
	}
	game = game_update_role(game);
	interface_act_update_role(game);
}
