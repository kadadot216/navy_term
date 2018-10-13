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
	//game_t	game = game_setup(P1);
	sigquery_t	query = sq_new();

	sq_compose_query(&query, "D2");
	sq_display_bitfield(&query);
	//board_display(game.board);
	return (0);
}
