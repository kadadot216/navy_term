/*
** EPITECH PROJECT, 2018
** interface_sigactions.h
** File description:
** Header file for Signal functions for interface
*/

#ifndef __INTERFACE_SIG_H__
#define __INTERFACE_SIG_H__

#include "signals.h"

// SIGACTIONS
void	sig_get_p2pid(int sig, siginfo_t *info, void *context);

#endif /* __INTERFACE_SIG_H__ */