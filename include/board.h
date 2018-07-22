/*
** EPITECH PROJECT, 2018
** board.h
** File description:
** Header file for board structure related functions
*/

#ifndef __BOARD_H__
#define __BOARD_H__

#include "types.h"

board_t		**init_board();
board_t		**unset_board(board_cell_t **table);
board_t		**destroy_board(board_t **board);
void		display_board(board_t **board);

#endif
