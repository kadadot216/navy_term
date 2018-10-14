/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for GDB debuging
*/

#include "navy.h"
#include "signals.h"
#include "interface_act.h"
#include "my.h"

#include <stdio.h>


int	init_game(game_t *game, char **av)
{
	interface_act_init_as(game);
	if (game->me == P1) {
		print_my_pid();
		my_putstr_fd(1, "waiting for ennemy connection...\n");
		interface_act_wait_for_epid();
		usleep(WAIT_OFFSET);
		interface_act_send_hello();
	} else if (game->me == P2) {
		interface_act_parse_pid(av[1]);
		interface_act_send_hello();
		interface_act_wait_for_epid();
	}
	return (init_check_connected());
}

void	turn_attack(game_t *game, char *prompt)
{
	prompt_attack(prompt);
	printf("Prompted %s\n", prompt);
	interface_act_compose_query(prompt);
	interface_act_send_query();
	my_memset(prompt, '\0', 2);
}

void	turn_wait(game_t *game, char *prompt)
{
	int	status = 0;
	int	index = -1;

	print_my_pid();
	printf("waiting for ennemy's attack...\n");
	status = interface_act_receive_query();
	if (status == 1) {
		index = interface_act_retrieve_coords();
		printf("Index is %d\n", index);
		prompt = get_coords_from_idx(prompt, index);
		printf("Retrieved coordinates are %s\n", prompt);
	}
	my_memset(prompt, '\0', 2);
}

void	play_turn(game_t *game, char *prompt)
{
	if (game->role == ROLE_PLAY) {
		turn_attack(game, prompt);
	} else if (game->role == ROLE_WAIT) {
		turn_wait(game, prompt);
	}
	game = game_update_role(game);
}

void	play_game(game_t *game)
{
	board_t	ennemy;
	char	prompt[3] = {'\0'};

	board_init(ennemy);
	while (interface_connected() && game->lives > 0) {
		play_turn(game, prompt);
	}
}

int	navy_game(int ac, char **av)
{
	game_t	game;

	game = game_setup_as(ac);
	if (!game_parse_map_as(&game, av)) {
		return (84);
	}
	printf("Player %d!\n", (game.me + 1));
	if (!init_game(&game, av))
		return (84);
	db_interface_printall();
	play_game(&game);
	return (0);
}

int	main(int ac, char **av)
{
	int	status = 0;

	if (check_for_help(ac, av)) {
		print_help_msg(av[0]);
		return (0);
	}
	if (!navy_argchecks(ac, av)) {
		print_help_msg(av[0]);
		return (84);
	}
	status = navy_game(ac, av);
	return (status);
}
