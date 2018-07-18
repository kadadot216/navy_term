#include <stdlib.h>
#include "board.h"
#include "game.h"
#include "parser.h"

static navy_game_t	*abort_game_init(navy_game_t *game)
{
	while (game->boards[MINE]) {
		game->boards[MINE] = destroy_board(game->boards[MINE]);
		game->boards[ENEMY] = destroy_board(game->boards[ENEMY]);
		game->boards[MINE] = NULL;
		game->boards[ENEMY] = NULL;
	}
	game->total_hits[MINE] = 0;
	game->total_hits[ENEMY] = 0;
	free(game);
	game = NULL;
	return (game);
}

navy_game_t	*init_game(navy_game_t *game, char const *filepath)
{
	game = malloc(sizeof(navy_game_t));

	game->status = ERROR;
	game->boards[MINE] = init_board();
	game->boards[ENEMY] = init_board();
	if (!parser_parse_file(game->boards[MINE], filepath)) {
		game = abort_game_init(game);
		return (NULL);
	}
	parser_parse_file(game->boards[ENEMY], filepath);
	game->total_hits[MINE] = 13;
	game->total_hits[ENEMY] = 13;
	game->status = RUNNING;
	return (game);
}

navy_game_t	*destroy_game(navy_game_t *game)
{
	game->boards[MINE] = destroy_board(game->boards[MINE]);
	game->boards[ENEMY] = destroy_board(game->boards[ENEMY]);
	game->boards[MINE] = NULL;
	game->boards[ENEMY] = NULL;
	game->total_hits[MINE] = 0;
	game->total_hits[ENEMY] = 0;
	free(game);
	game = NULL;
	return (game);
}
