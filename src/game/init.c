/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** Game initiation related functions
*/

#include <stdlib.h>
#include "board.h"

navy_game_t	*init_game(navy_game_t *game, char const *filepath)
{
	game = malloc(sizeof(navy_game_t));

	if (game == NULL) {
		return (NULL);
	}
	game->hits[MINE] = 0;
	game->hits[ENEMY] = 0;
	game->boards[MINE] = init_board();
	game->boards[ENEMY] = init_board();


	return (game);
}
