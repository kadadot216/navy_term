/*
** EPITECH PROJECT, 2018
** com_interface_debug.c
** File description:
** Com interface debug
*/

#include <stdio.h>
#include "signals.h"

extern interface_t	interface;

void	db_interface_print_pid(void)
{
	printf("Ennemy's PID: %d\n", (int)&interface.epid);
}

void	db_interface_print_query(void)
{
	sq_display_bitfield(&interface.uquery);
}

void	db_interface_print_header(void)
{
	sq_display_header(&interface.uquery);
}

void	db_interface_print_connected(void)
{
	char	*messages[] = {
		"connected",
		"disconnected"
	};

	printf("Interface %s\n", messages[interface.connected]);
}
