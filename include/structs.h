#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include "stypes.h"
#include <sys/types.h>
#include <signal.h>

struct	pos_s {
	uint_t	y;
	uint_t	x;
};

struct	parser_s {
	int	x;
	int	y;
};

struct	navy_game_s {
	player_t	me;
	game_status_t	status;
	board_t	**boards[2];
	uint_t	total_hits[2];
};

struct	com_interface_s {
	int		connected;
	int		query;
	int		bitval;
	player_t	turn;
	pid_t		epid;
	struct sigaction	sig;
};

#endif
