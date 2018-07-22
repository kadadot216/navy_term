#include <stdlib.h>
#include <signal.h>
#include "types.h"
#include "my.h"
#include "messages.h"
#include "interface.h"
#include "main.h"

extern	com_interface_t	iface;

int	main(int ac, char **av)
{
	navy_game_t	*game = NULL;

	if (check_for_help(ac, av)) {
		print_help_msg(av[0]);
		return (0);
	}
	iface = init_interface();
	game = init_game_as(game, ac, av);
	if (game == NULL) {
		return (84);
	}
	if (play_game(game) == 0) {
		destroy_game(game);
		return (84);
	}
	destroy_game(game);
	return (0);
}
