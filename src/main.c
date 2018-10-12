/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for navy game
*/

#include "navy.h"
#include "my.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	board_t	board = {0};

	board_init(board);
	board_display(board);
	return (0);
}
