/*
** EPITECH PROJECT, 2018
** com_interface_sig.c
** File description:
** Interface sig handler functions
*/

#include <unistd.h>
#include "navy.h"
#include "my.h"
#include "interface_act.h"

interface_t	interface;

void	sig_get_p2pid(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)sig;
	interface.epid = info->si_pid;
	usleep(500);
}
