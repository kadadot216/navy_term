/*
** EPITECH PROJECT, 2018
** com_interface.c
** File description:
** Communication interface functions
*/

#include "navy.h"
#include "signals.h"
#include "interface_act.h"
#include "interface_sigactions.h"

interface_t	interface;

void	interface_act_reset_sig(void)
{
	interface_init_sig(&interface);
}

void	interface_act_init_as(game_t *game)
{
	interface_act_init();
	interface_act_update_role(game);
}

int	interface_act_receive_query(void)
{
	int	timeout = 0;
	int	sigfield[8] = {0};

	interface_act_reset_query();
	interface.sig.sa_sigaction = &sig_get_query;
	sigaction(SIGUSR1, &interface.sig, NULL);
	sigaction(SIGUSR2, &interface.sig, NULL);
	while (interface.bc < 8) {
		timeout = !(usleep(TIME_OUT));
		if (timeout) {
			interface_act_set_timeout();
			interface_act_reset_query();
			return (-1);
		}
		sigfield[interface.bc - 1] = interface.signal;
	}
	interface_map_query(&interface, sigfield);
	return (1);
}

int	interface_act_receive_coords(void)
{
	int status = -1;

	status = interface_act_receive_query();
	if (!sq_header_is_msg(&interface.uquery))
		return (-1);
	return (status);
}

int	interface_act_receive_response(void)
{
	int	status = -1;
	int	hit = -1;

	status = interface_act_receive_query();
	hit = sq_header_check_hit(&interface.uquery);
	interface_act_reset_query();
	if (!status)
		return (-1);
	return (hit);
}
