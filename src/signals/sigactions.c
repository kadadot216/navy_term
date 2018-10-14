/*
** EPITECH PROJECT, 2018
** com_interface_sig.c
** File description:
** Interface sig handler functions
*/

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
