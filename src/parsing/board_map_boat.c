/*
** EPITECH PROJECT, 2018
** parse_coords.c
** File description:
** Parsing coordinates functions
*/

#include <stdlib.h>
#include "navy.h"
#include "macros.h"

static int	check_cells_alignment(char *f_cell, char *l_cell)
{
	if (f_cell[0] != l_cell[0] && f_cell[1] == l_cell[1])
		return (0);
	else if (f_cell[0] == l_cell[0] && f_cell[1] != l_cell[1])
		return (1);
	else
		return (-1);
}

static int	cells_valid_ref_distance(int cell_distance, char boat_ref)
{
	return (cell_distance == (boat_ref - '0'));
}

static int	cell_path_crossed(board_t this, char *cell_ref, int align, int dist)
{
	cell_t	*elem_test = NULL;
	char	cell_copy[2] = {cell_ref[0], cell_ref[1]};

	while (dist > 0) {
		elem_test = board_access_cell(this, cell_copy);
		if (*elem_test != CELL_UNK) {
			return (0);
		}
		cell_copy[align]++;
		dist--;
	}
	return (1);
}

int	cell_inboard(char *cl)
{
	int	cell_not_empty = ((cl[0] != 0) && (cl[1] != 0));
	int	in_x_axis = ((cl[0] >= 0 + 'A') && (cl[0] <= MAX_X + 'A'));
	int	in_y_axis = ((cl[1] >= 0 + '1') && (cl[1] <= MAX_Y + '1'));

	return ((cell_not_empty) && (in_x_axis) && (in_y_axis));
}

int	board_map_boat(board_t this, char boat_ref, char *f_cell, char *l_cell)
{
	int	alignment = -1;
	int	distance = 0;
	char	*cell_ref = NULL;
	cell_t	*elem = NULL;

	alignment = check_cells_alignment(f_cell, l_cell);
	if (alignment == -1 || !cell_inboard(f_cell) || !cell_inboard(l_cell))
		return (-1);
	distance = (l_cell[alignment] - f_cell[alignment]);
	cell_ref = (distance > 0) ? (f_cell) : (l_cell);
	distance = (ABS(distance) + 1);
	if (!cells_valid_ref_distance(distance, boat_ref) ||
		!cell_path_crossed(this, cell_ref, alignment, distance))
		return (-1);
	while (distance > 0) {
		elem = board_access_cell(this, cell_ref);
		*elem = boat_ref;
		cell_ref[alignment]++;
		distance--;
	}
	return (1);
}
