#ifndef __ENUMS_H__
#define __ENUMS_H__

enum	game_status_e {
	ERROR,
	RUNNING,
	ENEMY_WON,
	ME_WON
};

enum	board_e {
	NONE = '.',
	HIT = 'x',
	MISSED = 'o',
	L2 = '2',
	L3 = '3',
	L4 = '4',
	L5 = '5'
};

enum	x_axis_e {
	A = 0,
	B = 1,
	C = 2,
	D = 3,
	E = 4,
	F = 5,
	G = 6,
	H = 7
};

enum	board_type_e {
	MINE,
	ENEMY
};

#endif
