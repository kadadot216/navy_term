/*
** EPITECH PROJECT, 2018
** bit_processing.c
** File description:
** Bit processing functions
*/

#include "signals.h"

int	bit_retrieve_value(bit_t b, int n)
{
	if (b == 1)
		return (b << n);
	else if (b == 0)
		return (0);
	return (0);
	
}
