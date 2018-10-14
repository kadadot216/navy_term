/*
** EPITECH PROJECT, 2018
** pid.c
** File description:
** PID related functions
*/

#include <stdio.h>
#include "signals.h"
#include "my.h"

void	print_my_pid(void)
{
	pid_t	my_pid = getpid();

	my_putstr_fd(1, "my_pid: ");
	my_put_nbr((int)my_pid);
	my_putstr_fd(1, "\n");
}
