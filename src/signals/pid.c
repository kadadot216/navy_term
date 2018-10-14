/*
** EPITECH PROJECT, 2018
** pid.c
** File description:
** PID related functions
*/

#include <stdio.h>
#include "signals.h"

void	print_my_pid(void)
{
	pid_t	my_pid = getpid();

	printf("my_pid: %d\n", my_pid);
}
