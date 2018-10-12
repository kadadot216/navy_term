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

	board_init(board);
	board_map_boat(board, '2', "C3", "C4");
	debug_board_display(board);
	return (0);
}
