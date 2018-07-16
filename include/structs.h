/*
** EPITECH PROJECT, 2018
** structs.h
** File description:
** Header file for structs
*/

#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include "stypes.h"

struct	pos_s {
	uint_t	y;
	uint_t	x;
};

struct	board_cell_s {
	char	coords[2];
	struct	pos_s	pos;
};

struct	parser_s {
	int	offset_x;
	int	offset_y;
	char	lab;
	char	p1[2];
	char	p2[2];
};

struct	armada_s {
	uint_t	status;
	struct board_cell_s	(*ship2[2]);
	struct board_cell_s	(*ship3[3]);
	struct board_cell_s	(*ship4[4]);
	struct board_cell_s	(*ship5[5]);
};

struct	navy_game_s {
	game_status_t	status;
	struct	board_cell_s	**boards[2];
	struct	armada_s	*armada;
	uint_t	total_hits[2];
};

#endif
