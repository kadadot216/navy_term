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

int	navy_right_ac(int ac)
{
	return (ac >= 2 && ac <= 3);
}

int	navy_righ_args(int ac, char **av)
{
	if (ac == 2)
		return (my_arg_exists(av[1]));
	else if (ac == 3)
		return (my_arg_exists(av[1]) && my_arg_exists(av[2]) &&
			my_str_isnum(av[1]));
	return (0);
}

int	navy_argchecks(int ac, char **av)
{
	return (navy_right_ac(ac) && navy_righ_args(ac, av));
}
