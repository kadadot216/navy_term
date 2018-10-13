/*
** EPITECH PROJECT, 2018
** com_interface.c
** File description:
** Communication interface functions
*/

#include "navy.h"
#include "signals.h"

//void	interface_send_query(interface_t *this)
//{
//	if (this->epid > 0)  // && is_set_header
//
//}

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
	return (this);
}

interface_t	*interface_init(interface_t *this)
{
	this->connected = 0;
	this->epid  = 0;
	sq_reset(&this->uquery);
	return (this);
}

interface_t	*interface_set_role(interface_t *this, int role)
{
	this->role = (irole_t)role;
	return (this);
}
