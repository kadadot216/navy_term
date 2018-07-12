/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** Armada related functions
*/

#include <stdlib.h>
#include "types.h"

void	set_board_cell(board_cell_t *cell, dp_t rep)
{
	cell->coords[0] = 0;
	cell->coords[1] = 0;
	cell->x = 0;
	cell->y = 0;
	cell->rep = rep;
}

board_cell_t	*set_ship(board_cell_t	*cell, int length, dp_t rep)
{
	uint_t	i = 0;

	while (i < length) {
		set_board_cell(cell, rep);
		i++;
	}
	return (cell);
}

void	unset_ship(board_cell_t *cell, int length)
{
	cell = set_ship(cell, length, NONE);
}

void	set_ship2(board_cell_t *cell)
{
	cell = set_ship(cell,2, L2);
}

void	set_ship3(board_cell_t *cell)
{
	cell =  set_ship(cell,3, L3);
}

void	set_ship4(board_cell_t *cell)
{
	cell =  set_ship(cell,4, L4);
}

void	set_ship5(board_cell_t *cell)
{
	cell = set_ship(cell,4, L4);
}

armada_t	*init_armada(void)
{
	armada_t	*armada = NULL;

	armada = malloc(sizeof(armada_t));
	armada->status = 0;
	armada->total_hits = 14;
	set_ship2(armada->ship2);
	set_ship3(armada->ship3);
	set_ship4(armada->ship4);
	set_ship5(armada->ship5);
	return (armada);
}

armada_t	*unset_armada(armada_t *armada)
{
	armada->total_hits = 0;
	unset_ship(armada->ship2, 2);
	unset_ship(armada->ship3, 3);
	unset_ship(armada->ship4, 4);
	unset_ship(armada->ship5, 5);
	free(armada);
	armada = NULL;
	return (armada);
}
