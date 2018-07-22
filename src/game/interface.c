#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include "types.h"
#include "interface.h"

com_interface_t iface;

com_interface_t	init_interface(void)
{
	com_interface_t	iface;

	iface.sig.sa_flags = SA_SIGINFO;
	iface.sig.sa_sigaction = &receive_bit;
	sigaction(SIGUSR1, &iface.sig, NULL);
	sigaction(SIGUSR2, &iface.sig, NULL);
	iface.bitval = 1;
	iface.query = 0;
	iface.epid = 0;
	return (iface);
}

void	receive_bit_unsafe(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR2) {
		iface.query += iface.bitval;
		iface.bitval *= 2;
	} else if (sig == SIGUSR1) {
		iface.bitval *= 2;
	}
}

void	get_p2pid(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)sig;
	iface.epid = info->si_pid;
}

void	receive_bit(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR2 && (iface.epid == info->si_pid)) {
		iface.query += iface.bitval;
		iface.bitval *= 2;
	} else if (sig == SIGUSR1 && (iface.epid == info->si_pid)) {
		iface.bitval *= 2;
	}
}
