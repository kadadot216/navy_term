/*
** EPITECH PROJECT, 2018
** coords_table.c
** File description:
** For filling the coordinate table
*/

#include <stdlib.h>
#include "types.h"
#include "defs.h"

board_cell_t	**get_coords_table(void)
{
	uint_t	y = 0;
	uint_t	x = 0;
	char	alpha = 'A';
	char	num = '1';
	board_cell_t	**getter = NULL;

	getter = malloc(sizeof(board_cell_t *) * BOARD_H);
	while (y < BOARD_H) {
		getter[y] = malloc(sizeof(board_cell_t) * BOARD_W);
		while (x < BOARD_W) {
			getter[y][x].x = x;
			getter[y][x].y = y;
			getter[y][x].coords[0] = (alpha + y);
			getter[y][x].coords[1] = (num + x);
			x++;
		}
		x = 0;
		y++;
	}
	return (getter);
}

board_cell_t	**unset_coords_table(board_cell_t **table)
{
	uint_t	y = 0;
	uint_t	x = 0;

	while (y < BOARD_H) {
		while (x < BOARD_W) {
			table[y][x].x = 0;
			table[y][x].y = 0;
			table[y][x].coords[0] = 0;
			table[y][x].coords[1] = 0;
			x++;
		}
		free(table[y]);
		table[y] = NULL;
		x = 0;
		y++;
	}
	free(table);
	table = NULL;
	return (table);
}
