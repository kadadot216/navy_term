/*
** EPITECH PROJECT, 2018
** setup_as.c
** File description:
** Game setup according to input parameters
*/

#include "navy.h"

game_t	game_setup_as(int ac)
{
	game_t	game;

	if (ac == 3) {
		game = game_setup(P2);
	} else {
		game = game_setup(P1);
	}
	return (game);
}
