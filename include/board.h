/*
** EPITECH PROJECT, 2018
** board.h
** File description:
** Header file for board structure related functions
*/

#ifndef __BOARD_H__
#define __BOARD_H__

#include "types.h"

board_cell_t	**init_board(void);
board_cell_t	**unset_board(board_cell_t **table);

#endif
