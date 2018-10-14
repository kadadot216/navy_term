/*
** EPITECH PROJECT, 2018
** query_checks.c
** File description:
** Query checking functions
*/

#include "signals.h"

int	sq_header_is_msg(sigquery_t *this)
{
	return (this->h1 == 0 && this->h2 == 1);
}

int	sq_header_check_hit(sigquery_t *this)
{
	return (this->h1 == 1 && this->h2 == 1);
}
