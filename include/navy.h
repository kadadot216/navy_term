/*
** EPITECH PROJECT, 2018
** navy.h
** File description:
** Header file for Navy game and board
*/

#ifndef __NAVY_H__
#define __NAVY_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define	SIZE_X	(8)
#define	SIZE_Y	(8)
#define	BOARD_SIZE	((SIZE_X) * (SIZE_Y))
#define	MAX_X	((SIZE_X) - 1)
#define	MAX_Y	((SIZE_Y) - 1)
#define	NUM(x)	((x) - '0')
#define	LIVES	((NUM(CELL_2)) + (NUM(CELL_3)) + (NUM(CELL_4)) + (NUM(CELL_5)))
#define	OPEN_MODE	(O_RDONLY)
#define	PARSE_SEP	(':')
#define	PARSE_REQ	(4)
#define	BUFF_SIZE	(8)
#define	B_REF	(0)
#define	F_SEP	(1)
#define	F_CELL	(2)
#define	L_SEP	(4)
#define	L_CELL	(5)
#define	PARSE_TAIL	(7)

typedef enum	e_cell {
	CELL_HIT = 'x',
	CELL_MISS = 'o',
	CELL_UNK = '.',
	CELL_2 = '2',
	CELL_3 = '3',
	CELL_4 = '4',
	CELL_5 = '5'
}	cell_t;

typedef cell_t	board_t[BOARD_SIZE];

typedef enum	e_player {
	P1,
	P2
}	player_t;

typedef enum	e_role {
	ROLE_PLAY,
	ROLE_WAIT
}	role_t;

typedef struct	s_game {
	player_t	me;
	role_t		role;
	board_t		board;
	int		lives;
}	game_t;

cell_t	*board_access_cell(board_t board, char coords[2]);
cell_t	*board_get_cell(board_t board, int x, int y);
cell_t	*board_init(board_t this);
cell_t	*init_board(board_t this);
char	*prompt_attack(char *buffer);
int	cell_is_boat(cell_t *this);
game_t	*game_set_board(game_t *this);
game_t	*game_set_lives(game_t *this);
game_t	*game_set_player(game_t *this, player_t player);
game_t	*game_set_role(game_t *this, role_t role);
game_t	*game_set_role_from_player(game_t *this);
game_t	*game_unset(game_t *this);
game_t	*game_update_role(game_t *this);
game_t	game_setup(player_t player);
game_t	game_setup_as(int ac);
int	board_map_boat(board_t this, char bref, char *f_cell, char *l_cell);
int	cell_inboard(char *cl);
int	check_for_help(int ac, char **av);
int	game_parse_map(game_t *this, char const *filename);
int	game_parse_map_as(game_t *game, char **av);
int	navy_argchecks(int ac, char **av);
void	board_display(board_t this);
void	debug_board_display(board_t this);
void	print_help_msg(char const *pname);

#endif /* __NAVY_H__ */
