/*
** EPITECH PROJECT, 2018
** help_msg.c
** File description:
** Help message functions
*/

#include "my.h"

void	print_help_msg(char const *pname)
{
	my_putstr_fd(2, "USAGE\n");
	my_putstr_fd(2, pname);
	my_putstr_fd(2, " [first_player_pid] navy_positions\nDESCRIPTION\n"
		"\tfirst_player_pid:\tonly for the 2nd player.\tpid of the "
		"first player.\n\tnavy_positions:\tfile representing the "
		"positions of the ships.\n");
}
