/*
** EPITECH PROJECT, 2018
** query.c
** File description:
** Signal related functions
*/

#include "signals.h"

sigquery_t	*sq_reset_header(sigquery_t *this)
{
	this->h1 = 0;
	this->h2 = 0;
	return (this);
}

sigquery_t	*sq_reset_coords(sigquery_t *this)
{
	this->c1 = 0;
	this->c2 = 0;
	this->c3 = 0;
	this->c4 = 0;
	this->c5 = 0;
	this->c6 = 0;
	return (this);
}

sigquery_t	*sq_reset(sigquery_t *this)
{
	this = sq_reset_header(this);
	this = sq_reset_coords(this);
	return (this);
}

sigquery_t	sq_new(void)
{
	sigquery_t	new;

	sq_reset_header(&new);
	sq_reset_coords(&new);
	return (new);
}
