/*
** EPITECH PROJECT, 2018
** parse_coords.c
** File description:
** Parsing coordinates functions
*/

#include <stdlib.h>
#include "navy.h"
#include "macros.h"

int	check_cells_alignment(char *f_cell, char *l_cell)
{
	if (f_cell[0] != l_cell[0] && f_cell[1] == l_cell[1])
		return (0);	// Horizontal
	else if (f_cell[0] == l_cell[0] && f_cell[1] != l_cell[1])
		return (1);	// Vertical
	else
		return (-1);	// Invalid
}

int	cells_valid_ref_distance(int cell_distance, char boat_ref)
{
	return (ABS(cell_distance) == (boat_ref - '0'));
}

int	board_map_boat(board_t this, char boat_ref, char *f_cell, char *l_cell)
{
	int	alignment = -1;
	int	distance = 0;
	char	*cell_ref = NULL;
	cell_t	*elem = NULL;

	alignment = check_cells_alignment(f_cell, l_cell);
	if (alignment == -1)
		return (-1);
	distance = (l_cell[alignment] - f_cell[alignment] + 1);
	cell_ref = (distance > 0) ? (f_cell) : (l_cell);
	if (!cells_valid_ref_distance(distance, boat_ref))
		return (-1);
	while (distance > 0) {
		elem = board_access_cell(this, cell_ref);
		*elem = boat_ref;
		cell_ref[alignment]++;
		distance--;
	}
	return (1);
}

// PLUS
// =>
// |
// v

// MINUS
// <=
// ^
// | 

// 49 - 48 = 1
// 48 - 49 = -1
// 2:A1:A2
// alignement = check_cells_alignment(f, l) => 1
// distance = ABS(f_cell[alignement] - l_cell[alignement]) => 1
// A-A = 0
