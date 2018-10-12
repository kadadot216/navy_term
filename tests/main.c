/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for GDB debuging
*/

#include "navy.h"
#include "my.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	game_t	game = game_setup(P1);
	int	parsing_status = 0;

	parsing_status = game_parse_map(&game, av[1]);
	board_display(game.board);
	return (0);
}
