#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "types.h"
#include "interface.h"
#include "defs.h"

extern	com_interface_t	iface;

int	receive_query(void)
{
	int	received = 0;
	int	tstat = 0;

	while (iface.bitval < 16) {
		tstat = usleep(SLEEP);
		if (tstat != -1) {
			return (0);
		}
	}
	received = iface.query;
	iface.query = 0;
	iface.bitval = 1;
	return (received);
}

int	receive_connection_query(void)
{
	int	query = 0;

	iface.sig.sa_sigaction = &receive_bit_unsafe;
	sigaction(SIGUSR1, &iface.sig, NULL);
	sigaction(SIGUSR2, &iface.sig, NULL);
	query = receive_query();
	if (query == 15) {
		iface.sig.sa_sigaction = &get_p2pid;
		sigaction(SIGUSR1, &iface.sig, NULL);
		if (usleep(SLEEP) != -1) {
			return (0);
		}
		iface.sig.sa_sigaction = &receive_bit;
		sigaction(SIGUSR1, &iface.sig, NULL);
		sigaction(SIGUSR2, &iface.sig, NULL);
		return (1);
	}
	return (0);
}

static void	build_sigword(int sigword[], int value)
{
	int	bitval = 8;
	int	idx = 3;

	while (value > 0 && value < 16 && idx >= 0) {
		if (value >= bitval) {
			sigword[idx] = SIGUSR2;
			value -= bitval;
			bitval /= 2;
		}
		else if (value < bitval) {
			sigword[idx] = SIGUSR1;
			bitval /= 2;
		}
		idx--;
	}
}

void	send_query(int value, pid_t epid)
{
	int	sigword[4] = {0};
	int	idx = 0;

	build_sigword(sigword, value);
	while (idx < 4) {
		usleep(30);
		kill(epid, sigword[idx]);
		idx++;
	}
}
