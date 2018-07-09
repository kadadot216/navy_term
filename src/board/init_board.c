/*
** EPITECH PROJECT, 2018
** init_board.c
** File description:
** Board initiation functions
*/

#include <stdlib.h>
#include "types.h"

board_t	*init_board(void)
{
	board_t	*new = NULL;

	new = malloc(sizeof(board_t));
	if (new == NULL) {
		return (new);
	}
	new->h = 0;
	new->w = 0;
	new->dp = NULL;
	return (new);
}
