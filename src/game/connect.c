#include <unistd.h>
#include "my.h"
#include "types.h"
#include "query.h"
#include "messages.h"
#include "interface.h"

extern	com_interface_t	iface;

int	wait_for_connection(void)
{
	my_putstr_fd(1, "my pid: ");
	my_put_nbr(getpid());
	my_putchar('\n');
	my_putstr_fd(1, "waiting for enemy connection...\n");
	iface.connected = receive_connection_query();

	if (iface.connected == 0) {
		my_putstr_fd(2, "\nconnexion timed out...\n");
		return (0);
	} else if (iface.connected == 1) {
		my_putstr_fd(1, "\nenemy connected\n");
		return (1);
	}
	my_putstr_fd(2, "wrong PID or unexcpected signal\n");
	return (0);
}

int	send_connection_sig(void)
{
	my_putstr_fd(1, "my pid: ");
	my_put_nbr(getpid());
	my_putchar('\n');
	send_query(15, iface.epid);
	usleep(30);
	kill(iface.epid, SIGUSR1);
	my_putstr_fd(1, "successfully connected\n");
	return (1);
}
