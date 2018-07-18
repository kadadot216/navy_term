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

struct	parser_s {
	int	x;
	int	y;
};

struct	navy_game_s {
	game_status_t	status;
	board_t	**boards[2];
	uint_t	total_hits[2];
};

#endif
