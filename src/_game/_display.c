/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** Display related functions
*/

#include "my.h"
#include "types.h"
#include "board.h"

void	display_game(navy_game_t *game)
{
	my_putstr_fd(1, "my positions:\n");
	display_board(game->boards[0]);
	my_putstr_fd(1, "\nenemy's positions:\n");
	display_board(game->boards[1]);
	my_putstr_fd(1, "\n");
}

void	display_attack_msg(parser_t *p)
{
	my_putchar(p->x + 'A');
	my_putchar(p->y + '1');
	my_putstr_fd(1, ": ");
}
