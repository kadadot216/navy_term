/*
** EPITECH PROJECT, 2018
** argparse.c
** File description:
** arg parsing related functions
*/

#include <stdio.h>
#include "my.h"
#include "interface_act.h"

int	get_p1pid(char const *arg)
{
	if (arg == NULL || arg[0] == '\0' || !my_str_isnum(arg))
		return (-1);
	interface_act_set_pid((pid_t) (my_getnbr(arg)));
	return (1);
}

int	check_for_help(int ac, char **av)
{
	int	i = 0;

	while (i < ac) {
		if (my_strcmp(av[i], "-h") == 0) {
			return (1);
		}
		i++;
	}
	return (0);
}
