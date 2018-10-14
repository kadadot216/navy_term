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

int	cell_is_boat(cell_t *this)
{
	if (*this == CELL_2 || *this == CELL_3 ||
		*this == CELL_4 || *this == CELL_5)
		return (1);
	else
		return (0);
}
