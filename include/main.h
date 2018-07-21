/*
** EPITECH PROJECT, 2018
** main.h
** File description:
** Header file for main.c
*/

#ifndef __MAIN_H__
#define __MAIN_H__

#include "types.h"

navy_game_t	*init_game(navy_game_t *game, char const *filepath, player_t
		player);
navy_game_t	*destroy_game(navy_game_t *game);
int		play_game(navy_game_t *game);

#endif

