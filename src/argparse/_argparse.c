/*
** EPITECH PROJECT, 2018
** argparse.c
** File description:
** arg parsing related functions
*/

#include "my.h"
#include "types.h"

extern	com_interface_t	iface;

// Rewriting the function
// get_p1pid
// if (!my_strisnum(arg))
// 	return (-1);
// else
// 	pid = my_getnbr(arg);

int	get_p1pid(char const *arg)
{
	int	i = 0;

	while (arg[i] != '\0') {
		if (!(arg[i] >= '0' && arg[i] <= '9')) {
			return (0);
		}
		iface.epid *= 10;
		iface.epid += (arg[i] - '0');
		i++;
	}
	return (1);
}

int	check_for_help(int ac, char **av)
{
	uint_t	i = 0;

	while (i < (uint_t) ac) {
		if (my_strcmp(av[i], "-h") == 0) {
			return (1);
		}
		i++;
	}
	return (0);
}
