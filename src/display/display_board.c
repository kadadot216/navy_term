/*
** EPITECH PROJECT, 2018
** display_board.c
** File description:
** Related functions for displaying a board
*/

#include "types.h"
#include "my.h"

void	display_board(board_t *board)
{
	uint_t	y = 0;
	char	alpha = 'A';
	char	num = '1';

	my_putchar(' ');
	while (alpha <= 'H') {
		my_putchar(alpha);
		my_putchar(' ');
		alpha++;
	}
	my_putcharx_fd(1, '-', 8);
	my_putchar('\n');
	while (y < 8) {
		my_putchar(num + y);
		my_putchar(' ');
		my_putstr_fd(1, (char *) board[y]);
		y++;
	}
}
