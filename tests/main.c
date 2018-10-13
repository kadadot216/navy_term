/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for GDB debuging
*/

#include "navy.h"
#include "signals.h"
#include "my.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	game_t	game = game_setup(P1);
	int	parsing_status = 0;
	int	nb = 0;
	char	buff[3] = {'\0'};

	parsing_status = game_parse_map(&game, av[1]);
	nb = sq_compose_nb(0, "G5");
	get_coords_from_idx(buff, nb);
	game.board[nb] = CELL_HIT;
	printf("Retrived buffer is: %s\n", buff);
	board_display(game.board);
	return (0);
}
