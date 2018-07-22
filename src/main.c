/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file
*/

#include <stdlib.h>
#include <signal.h>
#include "types.h"
#include "my.h"
#include "messages.h"
#include "main.h"

void	receive_bit(int sig, siginfo_t *info, void *context);

static com_interface_t	init_interface(void)
{
	com_interface_t	iface;

	iface.sig.sa_flags = SA_SIGINFO;
	iface.sig.sa_sigaction = &receive_bit;
	sigaction(SIGUSR1, &iface.sig, NULL);
	sigaction(SIGUSR2, &iface.sig, NULL);
	iface.bitval = 1;
	iface.query = 0;
	iface.epid = 0;
	return (iface);
}

com_interface_t iface;

int	get_p1pid(char const *arg)
{
	int	i = 0;

	while (arg[i] != '\0') {
		if (!(arg[i] >= '0' && arg[i] <= '9')) {
			return (0);
		}
		iface.epid *= 10;
		iface.epid += (arg[i] - '0');
		i++;
	}
	return (1);
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

int	main(int ac, char **av)
{
	navy_game_t	*game = NULL;

	iface = init_interface();
	game = init_game_as(game, ac, av);
	if (game == NULL) {
		my_putstr_fd(2, "Something's wrong.\n");
		return (84);
	}
	if (play_game(game) == 0) {
		return (84);
	}
	destroy_game(game);
	my_putstr_fd(1, "All good\n");
	return (0);
}
