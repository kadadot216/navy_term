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

int	main(int ac, char **av)
{
	game_t	game;

	if (check_for_help(ac, av)) {
		print_help_msg(av[0]);
		return (0);
	}
	game = game_setup(P1);
	interface_act_init_as(&game);
	db_interface_printall();
	//if (game == NULL) {
	//	return (84);
	//}
	//if (play_game(game) == 0) {
	//	destroy_game(game);
	//	return (84);
	//}
	//destroy_game(game);
	return (0);
}
