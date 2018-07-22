/*
** EPITECH PROJECT, 2018
** interface.h
** File description:
** Header file for interface structure's functions
*/

#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <sys/types.h>
#include <signal.h>
#include "types.h"

com_interface_t	init_interface(void);
void	receive_bit_unsafe(int sig, siginfo_t *info, void *context);
void	get_p2pid(int sig, siginfo_t *info, void *context);
void	receive_bit(int sig, siginfo_t *info, void *context);
void	receive_bit(int sig, siginfo_t *info, void *context);

#endif
