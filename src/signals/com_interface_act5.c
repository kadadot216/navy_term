#include "navy.h"
#include "signals.h"
#include "interface_act.h"

interface_t	interface;

int	interface_act_retrieve_coords(void)
{
	int	index = -1;

	index = message_retrieve_value(&interface.uquery);
	return (index);
}

void	interface_act_send_query(void)
{
	interface_send_bit(interface.uquery.h1);
	usleep(WAIT_OFFSET);
	interface_send_bit(interface.uquery.h2);
	usleep(WAIT_OFFSET);
	interface_send_bit(interface.uquery.c1);
	usleep(WAIT_OFFSET);
	interface_send_bit(interface.uquery.c2);
	usleep(WAIT_OFFSET);
	interface_send_bit(interface.uquery.c3);
	usleep(WAIT_OFFSET);
	interface_send_bit(interface.uquery.c4);
	usleep(WAIT_OFFSET);
	interface_send_bit(interface.uquery.c5);
	usleep(WAIT_OFFSET);
	interface_send_bit(interface.uquery.c6);
	usleep(WAIT_OFFSET);
	interface_act_reset_query();
}

void	interface_act_send_response(int hit)
{
	interface_send_bit((bit_t) hit);
}

void	interface_act_compose_attack(char *prompt)
{
	sq_header_set_msg(&interface.uquery);
	interface_set_query(&interface, prompt);
}
