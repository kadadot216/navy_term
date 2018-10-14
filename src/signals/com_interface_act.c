/*
** EPITECH PROJECT, 2018
** com_interface_act.c
** File description:
** Interface actions
*/

#include "navy.h"
#include "signals.h"

interface_t	interface;

void	interface_act_set_pid(pid_t pid)
{
	interface_set_pid(&interface, pid);
}

void	interface_act_reset_query(void)
{
	interface_reset_query(&interface);
}

void	interface_act_set_query(char *prompt)
{
	interface_set_query(&interface, prompt);
}

void	interface_act_init(void)
{
	interface_init(&interface);
}

void	interface_act_update_role(game_t *game)
{
	interface_set_role(&interface, (int)game->role);
}

void	interface_act_set_timeout(void)
{
	interface_set_timeout(&interface);
}

void	interface_act_set_connected(void)
{
	interface_set_connected(&interface);
}

void	interface_act_set_disconnected(void)
{
	interface_set_disconnected(&interface);
}

int	connection_timed_out(void)
{
	if (interface.timeout) {
		return (1);
	}
	else {
		return (0);
	}
}

void	interface_act_init_as(game_t *game)
{
	interface_act_init();
	interface_act_update_role(game);
}
