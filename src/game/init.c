/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** Game initiation related functions
*/

#include <stdlib.h>
#include "board.h"
#include "game.h"

navy_game_t	*init_game(navy_game_t *game, char const *filepath)
{
	game = malloc(sizeof(navy_game_t));

	if (game == NULL) {
		return (NULL);
	}
	game->boards[MINE] = init_board();
	game->boards[ENEMY] = init_board();
	game->armada = init_armada();
// map armada
// remap armada into board
	if (game->armada->status == 0) {
		game->status = ERROR;
		return (game);
	}
	return (game);
}
