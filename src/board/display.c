#include "navy.h"
#include "my.h"

static void	x_axis_display(cell_t *start)
{
	int	idx = 0;

	while (idx < SIZE_X) {
		my_putchar(start[idx]);
		my_putchar(' ');
		idx++;
	}
	my_putchar('\n');
}

static void	y_axis_display(char mark, char sep)
{
	my_putchar(mark);
	my_putchar(sep);
}

static void	x_axis_display_header(void)
{
	int	idx = 0;

	y_axis_display(' ', '|');
	while (idx < SIZE_X) {
		my_putchar(idx + 'A');
		my_putchar(' ');
		idx++;
	}
	my_putchar('\n');
}

void	board_display(board_t this)
{
	int	y = 0;

	x_axis_display_header();
	y_axis_display('-', '+');
	my_putcharx_fd(1, '-', (SIZE_X * 2 - 1));
	my_putchar('\n');
	while (y < BOARD_SIZE) {
		y_axis_display(((char)(y / SIZE_X)) + '1', '|');
		x_axis_display(&this[y]);
		y += SIZE_X;
	}
}
