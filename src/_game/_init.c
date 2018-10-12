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
	while (game->boards[0]) {
		game->boards[0] = destroy_board(game->boards[0]);
		game->boards[1] = destroy_board(game->boards[1]);
		game->boards[0] = NULL;
		game->boards[1] = NULL;
	}
	game->total_hits[0] = 0;
	game->total_hits[1] = 0;
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
	game->boards[0] = init_board();
	game->boards[1] = init_board();
	if (!parser_parse_file(game->boards[0], filepath)) {
		game = abort_game_init(game);
		return (NULL);
	}
	game->total_hits[0] = 13;
	game->total_hits[1] = 13;
	game->status = RUNNING;
	return (game);
}

navy_game_t	*init_game_as(navy_game_t *game, int ac, char **av)
{
	if (ac == 1 || ac > 3) {
		return (NULL);
	} else if (ac == 2) {
		return (init_game(game, av[1], P1));
	} else if (ac == 3 && get_p1pid(av[1])) {
		return (init_game(game, av[2], P2));
	}
	return (NULL);
}

navy_game_t	*destroy_game(navy_game_t *game)
{
	game->boards[0] = destroy_board(game->boards[0]);
	game->boards[1] = destroy_board(game->boards[1]);
	game->boards[0] = NULL;
	game->boards[1] = NULL;
	game->total_hits[0] = 0;
	game->total_hits[1] = 0;
	free(game);
	game = NULL;
	return (game);
}
