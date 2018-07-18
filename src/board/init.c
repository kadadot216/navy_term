#include <stdlib.h>
#include "types.h"
#include "my.h"
#include "defs.h"

board_t	*set_board_line(board_t *board, board_t sb, uint_t size)
{
	uint_t	i = 0;

	while (i < size) {
		board[i] = sb;
		i++;
	}
	return (board);
}

board_t	**init_board(void)
{
	uint_t	y = 0;
	board_t	**board = malloc(sizeof(board_t *) * 8);

	while (y < 8) {
		board[y] = malloc(sizeof(board_t) * 8);
		board[y] = set_board_line(board[y], NONE, 8);
		y++;
	}
	return (board);
}

board_t	**destroy_board(board_t **board)
{
	uint_t	y = 0;

	while (y < 8) {
		board[y] = set_board_line(board[y], NONE, 8);
		free(board[y]);
		board[y] = NULL;
		y++;
	}
	free(board);
	board[y] = NULL;
	return (board);
}
