/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** Prompting related functions
*/

#include "my.h"
#include "navy.h"
#include <unistd.h>

static int	prompt_valid_attack(char *p)
{
	return (cell_inboard(p));
}

void	print_attack_msg(void)
{
	my_putstr_fd(1, "attack: ");
}

char	*prompt_attack(char *buffer)
{
	while (!(prompt_valid_attack(buffer))) {
		my_memset(buffer, '\0', 2);
		print_attack_msg();
		read(0, buffer, 2);
	}
	return (buffer);
}
