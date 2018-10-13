/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for GDB debuging
*/

#include "navy.h"
#include "signals.h"
#include "interface_act.h"
#include "my.h"

#include <stdio.h>

int	init_game(game_t *game, char **av)
{
	if (game->me == P1 && game_parse_map(game, av[1])) {
		//wait_for_connection
	} else if (game->me == P2 && game_parse_map(game, av[2])) {

	}
	return (0);
}

int	game_parse_map_as(game_t *game, char **av)
{
	if (game->me == P1 && (game_parse_map(game, av[1]) == -1))
		return (0);
	else if (game->me == P2 && (game_parse_map(game, av[2]) == -1))
		return (0);
	return (1);
}

int	navy_game(int ac, char **av)
{
	game_t	game;

	game = game_setup_as(ac);
	if (!game_parse_map_as(&game, av)) {
		printf("Whoospie!\n");
		return (84);
	}
	printf("Player %d!\n", (game.me + 1));
	//if (!init_game(&game, av))
	//	return (84);
	interface_act_init_as(&game);
	db_interface_printall();
	board_display(game.board);
	return (0);
}

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
