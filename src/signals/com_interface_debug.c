/*
** EPITECH PROJECT, 2018
** com_interface_debug.c
** File description:
** Com interface debug
*/

#include <stdio.h>
#include "signals.h"

interface_t	interface;

void	db_interface_print_pid(void)
{
	printf("Ennemy's PID: %d\n", (int)interface.epid);
}

void	db_interface_print_query(void)
{
	sq_display_bitfield(&interface.uquery);
}

void	db_interface_print_header(void)
{
	sq_display_header(&interface.uquery);
}

void	db_interface_print_role(void)
{
	char	*messages[] = {
		"PLAYING",
		"WAITING"
	};

	printf("Role: %s\n", messages[interface.role]);
}

void	db_interface_print_connected(void)
{
	char	*messages[] = {
		"disconnected",
		"connected"
	};

	printf("Interface %d %s\n", interface.connected, 
		messages[interface.connected]);
}

void	db_interface_printall(void)
{
	db_interface_print_connected();
	db_interface_print_role();
	db_interface_print_pid();
	db_interface_print_header();
	db_interface_print_query();
}
