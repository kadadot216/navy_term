#include "main.h"

int	main(int ac, char **av)
{
	int	status = 0;

	if (check_for_help(ac, av)) {
		print_help_msg(av[0]);
		return (0);
	}
	if (!navy_argchecks(ac, av)) {
		print_help_msg(av[0]);
		return (84);
	}
	status = navy_game(ac, av);
	return (status);
}
