/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** Game initiation related functions
*/

#include <stdlib.h>
#include "types.h"
#include "board.h"
#include "game.h"
#include "parser.h"

static navy_game_t	*abort_game_init(navy_game_t *game)
{
	while (game->boards[P1]) {
		game->boards[P1] = destroy_board(game->boards[P1]);
		game->boards[P2] = destroy_board(game->boards[P2]);
		game->boards[P1] = NULL;
		game->boards[P2] = NULL;
	}
	game->total_hits[P1] = 0;
	game->total_hits[P2] = 0;
	free(game);
	game = NULL;
	return (game);
}

navy_game_t	*init_game(navy_game_t *game, char const *filepath,
		player_t player)
{
	game = malloc(sizeof(navy_game_t));

	game->me = player;
	game->status = ERROR;
	game->boards[P1] = init_board();
	game->boards[P2] = init_board();
	if (!parser_parse_file(game->boards[P1], filepath)) {
		game = abort_game_init(game);
		return (NULL);
	}
	parser_parse_file(game->boards[P2], filepath);
	game->total_hits[P1] = 13;
	game->total_hits[P2] = 13;
	game->status = RUNNING;
	return (game);
}

navy_game_t	*destroy_game(navy_game_t *game)
{
	game->boards[P1] = destroy_board(game->boards[P1]);
	game->boards[P2] = destroy_board(game->boards[P2]);
	game->boards[P1] = NULL;
	game->boards[P2] = NULL;
	game->total_hits[P1] = 0;
	game->total_hits[P2] = 0;
	free(game);
	game = NULL;
	return (game);
}
