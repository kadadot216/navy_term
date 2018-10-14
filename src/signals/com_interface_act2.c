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

void	interface_act_wait_for_p2pid(void)
{
	int	wait_stat = 0;

	interface.sig.sa_sigaction = &sig_get_p2pid;
	sigaction(SIGUSR1, &interface.sig, NULL);
	sigaction(SIGUSR2, &interface.sig, NULL);
	wait_stat = usleep(TIME_OUT);
	if (wait_stat == 0)
		interface_act_set_timeout();
	else {
		interface_act_set_connected();
	}
}

void	interface_act_send_hello(void)
{
	kill(interface.epid, SIGUSR1);
}

int	init_checks_p1(void)
{
	if (connection_timed_out() || interface.epid == 0)
		return (0);
	else
		return (1);
}

int	init_checks_p2(void)
{
	if (interface.epid == 0)
		return (0);
	else
		return (1);
}
