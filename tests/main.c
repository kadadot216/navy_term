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
	board_t	board = {0};
	char	c1[2] = "F5";
	char	c2[2] = "F9";

	board_init(board);
	board_map_boat(board, '5', c1, c2);
	debug_board_display(board);
	return (0);
}
