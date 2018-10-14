/*
** EPITECH PROJECT, 2018
** main.h
** File description:
** Header file for Main prototypes
*/

#ifndef __MAIN_H__
#define __MAIN_H__

#include "navy.h"
#include "signals.h"
#include "interface_act.h"
#include "my.h"

int	init_game(game_t *game, char **av);
void	play_game(game_t *game);
int	navy_game(int ac, char **av);
int	init_game(game_t *game, char **av);
void	play_game(game_t *game);
int	navy_game(int ac, char **av);
void	turn_attack(char *prompt);
game_t	*update_board(int index, game_t *game);
void	turn_wait(game_t *game);
void	play_turn(game_t *game, char *prompt);

#endif /* __MAIN_H__ */
