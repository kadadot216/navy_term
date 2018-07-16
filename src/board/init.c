/*
** EPITECH PROJECT, 2018
** coords_table.c
** File description:
** For filling the coordinate table
*/

#include <stdlib.h>
#include "types.h"
#include "my.h"
#include "defs.h"

board_t	**init_board(void)
{
	uint_t	y = 0;
	board_t	**board = malloc(sizeof(board_t *) * 8);

	while (y < 8) {
		board[y] = malloc(sizeof(board_t) * 8);
		my_memset((char *) board[y], NONE, 8);
		y++;
	}
	return (board);
}
