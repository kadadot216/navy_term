#include "types.h"
#include "defs.h"
#include "my.h"

void	print_board_line(board_t *board, uint_t line)
{
	uint_t	i = 0;

	my_putchar(line + '1');
	my_putchar('|');
	while (i < BSIZE) {
		my_putchar(board[i]);
		my_putchar(' ');
		i++;
	}
	my_putchar('\n');
}

void	board_print_x_axis(void)
{
	uint_t	i = 0;

	my_putstr_fd(1, " |");
	while (i < BSIZE) {
		my_putchar(i + 'A');
		my_putchar(' ');
		i++;
	}
	my_putstr_fd(1, "\n-+");
	my_putcharx_fd(1, '-', (BSIZE * 2));
	my_putchar('\n');
}

void	display_board(board_t **board)
{
	uint_t	y = 0;

	board_print_x_axis();
	while (y < BSIZE) {
		print_board_line(board[y], y);
		y++;
	}
}
