#include <stdlib.h>
#include "types.h"
#include "my.h"
#include "messages.h"
#include "main.h"

int	main(int ac, char **av)
{
	navy_game_t	*game = NULL;

	game = init_game(game, av[1]);
	if (game == NULL) {
		my_putstr_fd(2, "Something's wrong.\n");
		return (84);
	}
	play_game(game);
	destroy_game(game);
	my_putstr_fd(1, "All good\n");
	return (0);
}
