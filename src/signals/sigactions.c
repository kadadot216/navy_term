#include "navy.h"
#include "my.h"
#include "interface_act.h"

interface_t	interface;

void	sig_get_epid(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)sig;
	interface.epid = info->si_pid;
	interface_act_set_connected();
}

void	sig_get_query(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if ((sig == SIGUSR1 || sig == SIGUSR2) && interface.role == I_WAIT) {
		interface.signal = sig;
		interface.bc++;
	}
}

void	sig_get_response(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if ((sig == SIGUSR1 || sig ==SIGUSR2) && interface.role == I_PLAY) {
		interface.signal = sig;
	}
}
