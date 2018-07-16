/*
** EPITECH PROJECT, 2018
** main.h
** File description:
** Header file for main.c
*/

#ifndef __MAIN_H__
#define __MAIN_H__

#include "types.h"

int	parser_parse_file(board_t **board, char const *filepath);
board_t	**init_board(void);
void	display_board(board_t **board);

#endif

