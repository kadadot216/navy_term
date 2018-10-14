/*
** EPITECH PROJECT, 2018
** coords_processing.c
** File description:
** Bit processing related functions
*/

#include "signals.h"

sigquery_t	*sq_header_set_cut(sigquery_t *this)
{
	this->h1 = 0;
	this->h2 = 0;
	return (this);
}

sigquery_t	*sq_cut_connection(sigquery_t *this)
{
	this = sq_header_set_cut(this);
	this = set_message_bit(this, 63);
	return (this);
}

sigquery_t	*sq_compose_msg_query(sigquery_t *this, char *prompt)
{
	int	idx = 0;

	idx = get_idx_from_coords(prompt);
	this = set_message_bit(this, idx);
	return (0);
}

int	message_retrieve_value(sigquery_t *this)
{
	int	res = 0;

	res += bit_retrieve_value(this->c1, 0);
	res += bit_retrieve_value(this->c2, 1);
	res += bit_retrieve_value(this->c3, 2);
	res += bit_retrieve_value(this->c4, 3);
	res += bit_retrieve_value(this->c5, 4);
	res += bit_retrieve_value(this->c6, 5);
	return (res);
}
