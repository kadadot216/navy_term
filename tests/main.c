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
	sigquery_t	query = sq_new();
	int	res = 0;

	sq_compose_msg_query(&query, av[1]);
	sq_display_bitfield(&query);
	res = message_retrieve_value(&query);
	printf("Retrieved value is: %d\n", res);
	game.board[res] = CELL_HIT;
	debug_board_display(game.board);
	return (0);
}
