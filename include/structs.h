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

struct	navy_game {
	game_status_t	status;
	struct	board_s	*board;
};

#endif
