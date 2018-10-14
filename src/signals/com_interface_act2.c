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

void	interface_send_bit(bit_t this)
{
	if (this)
		kill(interface.epid, SIGUSR2);
	else
		kill(interface.epid, SIGUSR1);
}

bit_t	bit_from_sig(int signal)
{
	if (signal == SIGUSR2)
		return (1);
	else if (signal == SIGUSR1)
		return (0);
	return (0);
}

interface_t	*interface_map_query(interface_t *this, int *sigfield)
{
	this->uquery.h1 = bit_from_sig(sigfield[0]);
	this->uquery.h2 = bit_from_sig(sigfield[1]);
	this->uquery.c1 = bit_from_sig(sigfield[2]);
	this->uquery.c2 = bit_from_sig(sigfield[3]);
	this->uquery.c3 = bit_from_sig(sigfield[4]);
	this->uquery.c4 = bit_from_sig(sigfield[5]);
	this->uquery.c5 = bit_from_sig(sigfield[6]);
	this->uquery.c6 = bit_from_sig(sigfield[7]);
	return (this);
}

int	interface_act_receive_query(void)
{
	int	timeout = 0;
	int	sigfield[8] = {0};

	interface.sig.sa_sigaction = &sig_get_query;

	while (interface.bc < 6) {
		timeout = !(usleep(TIME_OUT));
		if (timeout) {
			interface_act_set_timeout();
			return (-1);
		}
		sigfield[interface.bc] = interface.signal;
	}
	interface_map_query(&interface, sigfield);
	return (1);
}

void	interface_act_send_query(sigquery_t *query)
{
	interface_send_bit(query->h1);
	usleep(WAIT_OFFSET);
	interface_send_bit(query->h2);
	usleep(WAIT_OFFSET);
	interface_send_bit(query->c1);
	usleep(WAIT_OFFSET);
	interface_send_bit(query->c2);
	usleep(WAIT_OFFSET);
	interface_send_bit(query->c3);
	usleep(WAIT_OFFSET);
	interface_send_bit(query->c4);
	usleep(WAIT_OFFSET);
	interface_send_bit(query->c5);
	usleep(WAIT_OFFSET);
	interface_send_bit(query->c6);
	usleep(WAIT_OFFSET);
	interface_act_reset_query();
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
