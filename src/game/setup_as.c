#include "navy.h"

game_t	game_setup_as(int ac)
{
	game_t	game;

	if (ac == 3) {
		game = game_setup(P2);
	} else {
		game = game_setup(P1);
	}
	return (game);
}

int	game_parse_map_as(game_t *game, char **av)
{
	if (game->me == P1 && (game_parse_map(game, av[1]) == -1))
		return (0);
	else if (game->me == P2 && (game_parse_map(game, av[2]) == -1))
		return (0);
	return (1);
}
