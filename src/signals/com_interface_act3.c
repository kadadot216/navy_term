#include "navy.h"
#include "signals.h"

interface_t	interface;

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

int	interface_connected(void)
{
	return (interface.connected);
}
