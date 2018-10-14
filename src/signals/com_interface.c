/*
** EPITECH PROJECT, 2018
** com_interface.c
** File description:
** Communication interface functions
*/

#include "navy.h"
#include "signals.h"

interface_t	*interface_set_pid(interface_t *this, pid_t pid)
{
	this->epid = pid;
	return (this);
}

interface_t	*interface_set_query(interface_t *this, char *prompt)
{
	sq_compose_msg_query(&this->uquery, prompt);
	return (this);
}

interface_t	*interface_reset_query(interface_t *this)
{
	sq_reset(&this->uquery);
	this->bc = 0;
	this->signal = 0;
	return (this);
}

interface_t	*interface_init_sig(interface_t *this)
{
	this->sig.sa_flags = SA_SIGINFO;
	this->sig.sa_sigaction = 0;
	sigaction(SIGUSR1, &this->sig, 0);
	sigaction(SIGUSR2, &this->sig, 0);
	this = interface_reset_query(this);
	return (this);
}

interface_t	*interface_init(interface_t *this)
{
	this->connected = 0;
	this->epid = (pid_t) 0;
	this = interface_init_sig(this);
	return (this);
}
