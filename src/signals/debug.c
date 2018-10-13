/*
** EPITECH PROJECT, 2018
** debug.c
** File description:
** Signal debugging functions
*/

#include "signals.h"
#include <stdio.h>

void	sq_display_header(sigquery_t *this)
{
	printf("%d ", this->h2);
	printf("%d ", this->h1);
	printf("\n");
}

void	sq_display_bitfield(sigquery_t *this)
{
	printf("%d ", this->c6);
	printf("%d ", this->c5);
	printf("%d ", this->c4);
	printf("%d ", this->c3);
	printf("%d ", this->c2);
	printf("%d ", this->c1);
	printf("\n");
}
