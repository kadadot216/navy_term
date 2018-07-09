/*
** EPITECH PROJECT, 2018
** structs.h
** File description:
** Header file for structs
*/

#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include "stypes.h"

struct	board_cell_s {
	char	coords[2];
	uint_t	y;
	uint_t	x;
	ship_length_t	rep;
};

struct	navy_game_s {
	game_status_t	status;
	uint_t	hits[2];
	struct	board_cell_s	**boards[2];
};

#endif
