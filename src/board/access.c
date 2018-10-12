/*
** EPITECH PROJECT, 2018
** access.c
** File description:
** Board access functions
*/

#include "navy.h"

cell_t	*board_get_cell(board_t board, int x, int y)
{
	return (&board[y * SIZE_X + x]);
}

cell_t	*board_access_cell(board_t board, char *coords)
{
	return (board_get_cell(board, (coords[0] - 'A'), (coords[1] - '1')));
}
