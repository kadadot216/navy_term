#include "main.h"

int	init_game(game_t *game, char **av)
{
	interface_act_init_as(game);
	if (game->me == P1) {
		print_my_pid();
		my_putstr_fd(1, "waiting for enemy connection...\n");
		interface_act_wait_for_epid();
		usleep(WAIT_OFFSET);
		interface_act_send_hello();
		my_putstr_fd(1, "\nenemy connected\n");
	} else if (game->me == P2) {
		interface_act_parse_pid(av[1]);
		interface_act_send_hello();
		interface_act_wait_for_epid();
		print_my_pid();
		my_putstr_fd(1, "successfully connected\n");
	}
	return (init_check_connected());
}

void	play_game(game_t *game)
{
	board_t	ennemy;
	char	prompt[3] = {'\0'};

	board_init(ennemy);
	while (interface_connected() && game->lives > 0) {
		play_turn(game, ennemy, prompt);
	}
	if (game->lives > 0) {
		my_putstr_fd(1, "I won\n");
	} else {
		my_putstr_fd(1, "Enemy won\n");
	}
}

int	navy_game(int ac, char **av)
{
	game_t	game;

	game = game_setup_as(ac);
	if (!game_parse_map_as(&game, av)) {
		return (84);
	}
	if (!init_game(&game, av))
		return (84);
	play_game(&game);
	return (0);
}
