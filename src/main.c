#include <stdlib.h>
#include "types.h"
#include "my.h"
#include "messages.h"
#include "main.h"

int	main(int ac, char **av)
{
	navy_game_t	*game = NULL;

	board_t	**board = init_board();
	display_board(board);
	if (!parser_parse_file(board, av[1])) {
		my_putstr_fd(2, "Something's wrong.\n");
		return (84);
	}
	display_board(board);
	my_putstr_fd(1, "All good\n");
	return (0);
}
