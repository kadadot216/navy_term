/*
** EPITECH PROJECT, 2018
** coords_processing.c
** File description:
** Bit processing related functions
*/

#include "signals.h"

int	get_idx_from_coords(char *prompt)
{
	int	idx = 0;

	idx += (prompt[0] - 'A');
	idx += ((prompt[1] - '1') * (1 << 3));
	return (idx);
}

char	*get_coords_from_idx(char *buffer, int idx)
{
	buffer[0] = idx % (1 << 3) + 'A';
	buffer[1] = idx / (1 << 3) + '1';
	return (buffer);
}

sigquery_t	*set_message_bit(sigquery_t *this, int value)
{
	this->c1 = (value % BASE_2);
	value /= BASE_2;
	this->c2 = (value % BASE_2);
	value /= BASE_2;
	this->c3 = (value % BASE_2);
	value /= BASE_2;
	this->c4 = (value % BASE_2);
	value /= BASE_2;
	this->c5 = (value % BASE_2);
	value /= BASE_2;
	this->c6 = (value % BASE_2);
	value /= BASE_2;
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
