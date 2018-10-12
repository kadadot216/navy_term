/*
** EPITECH PROJECT, 2018
** navy.h
** File description:
** Header file for Navy game and board
*/

#ifndef __NAVY_H__
#define __NAVY_H__

#define	SIZE_X		(8)
#define	SIZE_Y		(8)
#define	BOARD_SIZE	((SIZE_X) * (SIZE_Y))

typedef enum	e_cell {
	CELL_HIT = 'o',
	CELL_MISS = 'x',
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


// NAVY
cell_t	board_get_cell(board_t board, int x, int y);
cell_t	*init_board(board_t this);
cell_t	*board_init(board_t this);
void	board_display(board_t this);

// PRINTING
void	print_help_msg(char const *pname);

#endif /* __NAVY_H__ */
