#include "navy.h"
#include "my.h"

void	debug_board_display(board_t this)
{
	int	i = 0;

	while (i < BOARD_SIZE) {
		my_putchar((char) this[i]);
		if ((i + 1) % SIZE_X == 0) {
			my_putchar('\n');
		}
		i++;
	}
}
