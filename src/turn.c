/*
** EPITECH PROJECT, 2018
** turn.c
** File description:
** Turn functions
*/

#include "main.h"

#include <stdio.h>

void	turn_attack(char *prompt, board_t enemy)
{
	int	hit = -1;
	char	*hit_msg[] = {"missed\n", "hit\n"};
	cell_t	cell_marks[] = {CELL_MISS, CELL_HIT};

	prompt_attack(prompt);
	interface_act_compose_attack(prompt);
	interface_act_send_query();
	hit = interface_act_receive_response();
	my_putstr_fd(1, prompt);
	my_putstr_fd(1, ": ");
	my_putstr_fd(1, hit_msg[hit]);
	enemy[get_idx_from_coords(prompt)] = cell_marks[hit];
}

game_t	*update_board(int index, game_t *game)
{
	int	hit = -1;

	if (cell_is_boat(&game->board[index])) {
		game->board[index] = CELL_HIT;
		hit = 1;
		game->lives--;
	}
	else {
		game->board[index] = CELL_MISS;
		hit = 0;
	}
	interface_act_send_response(hit);
	interface_act_send_query();
	return (game);
}

void	turn_wait(game_t *game)
{
	int	status = 0;
	int	index = -1;
	char	coords[3] = {'\0'};

	my_putstr_fd(1, "waiting for enemy's attack...\n");
	status = interface_act_receive_coords();
	if (status == 1) {
		index = interface_act_retrieve_coords();
		get_coords_from_idx(coords, index);
		game = update_board(index, game);
	}
}

void	game_display_boards(game_t *mine, board_t enemy)
{
	my_putstr_fd(1, "\nmy positions:\n");
	board_display(mine->board);
	my_putstr_fd(1, "\nenemy's positions:\n");
	board_display(enemy);
	my_putstr_fd(1, "\n");
}

void	play_turn(game_t *game, board_t enemy, char *prompt)
{
	game_display_boards(game, enemy);
	if (game->role == ROLE_PLAY) {
		turn_attack(prompt, enemy);
	}
	if (game->role == ROLE_WAIT) {
		turn_wait(game);
	}
	game = game_update_role(game);
	interface_act_update_role(game);
}
