/*
** EPITECH PROJECT, 2018
** enums.h
** File description:
** Header file for enums
*/

#ifndef __ENUMS_H__
#define __ENUMS_H__

enum	game_status_e {
	ERROR,
	RUNNING,
	ME_WON,
	ENEMY_WON
};

enum	dp_e {
	NONE = '.',
	HIT = 'x',
	MISSED = 'o',
	L2 = '2',
	L3 = '3',
	L4 = '4',
	L5 = '5'
};

enum	board_type_e {
	MINE,
	ENEMY
};

#endif
