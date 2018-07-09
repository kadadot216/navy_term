/*
** EPITECH PROJECT, 2018
** messages.c
** File description:
** Messages related functions for navy
*/

#include "my.h"

void	print_help_msg(char const *pname)
{
	my_putstr_fd("USAGE\n");
	my_putstr_fd(pname);
	my_putstr_fd(" [first_player_pid] navy_positions\nDESCRIPTION\n"
		"\tfirst_player_pid:\tonly for the 2nd player.\tpid of the "
		"first player.\n\tnavy_positions:\tfile representing the "
		"positions of the ships.\n");
}
