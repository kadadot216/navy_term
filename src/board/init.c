/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** Board initialization function
*/

#include "navy.h"

cell_t	*board_init(board_t this)
{
	int	idx = 0;

	while (idx < BOARD_SIZE) {
		this[idx] = CELL_UNK;
		idx++;
	}
	return (this);
}
