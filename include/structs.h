/*
** EPITECH PROJECT, 2018
** structs.h
** File description:
** Header file for structs
*/

#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include "stypes.h"

struct	board_s {
	uint_t	w;
	uint_t	h;	
	char	**dp;
};

struct	board_cell_s {
	char	coords[2];
	uint_t	y;
	uint_t	x;
};

struct	ship_s {
	char	r;
	char	*touche[2];
	ship_length_t	lenght;
	uint_t	ox;
	uint_t	oy;
	uint_t	ix;
	uint_t	iy;
};

struct	armada_s {
	struct ship_s	*s2;
	struct ship_s	*s3;
	struct ship_s	*s4;
	struct ship_s	*s5;
};

struct	navy_game_s {
	game_status_t	status;
	struct	armada_s	armada;
	struct	board_s	*board;
};

#endif
