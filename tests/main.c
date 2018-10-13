/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for GDB debuging
*/

#include "navy.h"
#include "signals.h"
#include "my.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	game_t	game = game_setup(P1);
	int	parsing_status = 0;
	int	nb = 0;

	parsing_status = game_parse_map(&game, av[1]);
	nb = sq_compose_nb(0, "H8");
	game.board[nb] = CELL_HIT;
	board_display(game.board);
	return (0);
}
