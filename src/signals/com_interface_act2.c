/*
** EPITECH PROJECT, 2018
** com_interface_act2.c
** File description:
** Interface actions part.2
*/

#include "navy.h"
#include "my.h"
#include "interface_act.h"
#include "interface_sigactions.h"

interface_t	interface;

void	interface_act_parse_pid(char const *arg)
{
	interface_act_set_pid((pid_t) (my_getnbr(arg)));
}

void	interface_act_wait_for_epid(void)
{
	int	timeout = 0;

	interface.sig.sa_sigaction = &sig_get_epid;
	sigaction(SIGUSR1, &interface.sig, NULL);
	sigaction(SIGUSR2, &interface.sig, NULL);
	timeout = !(usleep(TIME_OUT));
	if (timeout)
		interface_act_set_timeout();
}

void	interface_act_send_hello(void)
{
	kill(interface.epid, SIGUSR1);
}

int	init_check_connected(void)
{
	if (connection_timed_out() || interface.epid == 0 ||
		!interface_connected())
		return (0);
	else
		return (1);
}
