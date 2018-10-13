/*
** EPITECH PROJECT, 2018
** query.c
** File description:
** Signal related functions
*/

#include "signals.h"

sigquery_t	*sq_reset_header(sigquery_t *this)
{
	this->header = (0 << 0);
	this->header = (0 << 1);
	return (this);
}

sigquery_t	*sq_reset_coords(sigquery_t *this)
{
	this->coords = (0 << 0);
	this->coords = (0 << 1);
	this->coords = (0 << 2);
	this->coords = (0 << 3);
	this->coords = (0 << 4);
	this->coords = (0 << 5);
	return (this);
}

sigquery_t	sq_new(void)
{
	sigquery_t	new;

	sq_reset_header(&new);
	sq_reset_coords(&new);
	return (new);
}

#include <stdio.h>

int	sq_compose_nb(sigquery_t *this, char *prompt) //DELET
{
	int	bidx = 0;
	int	nb = 0;

	(void)this;
	(void)bidx;
	nb += (prompt[0] - 'A');
	printf("Encoded number: %d\n", nb);
	nb += ((prompt[1] - '1') * (1 << 3));
	printf("Encoded number: %d\n", nb);
	return (nb);
}
//"C2" => board[10] => case C2

sigquery_t	*sq_compose_query(sigquery_t *this, char *prompt)
{
	int	bidx = 0;
	int	nb = 0;

	(void)this;
	(void)bidx;
	nb += (prompt[0] - 'A');
	printf("Encoded number: %d\n", nb);
	nb += ((prompt[1] - '1') * (1 << 3)); // or SIZE_X
	printf("Encoded number: %d\n", nb);
	return (0);
}
//"C2" => (BigEnd) [00][010100] => Check at 10 => decypher => "C2"
char	*get_coords_from_idx(char *buffer, int idx)
{
	buffer[0] = idx % 8 + 'A';
	buffer[1] = idx / 8 + '1';
	return (buffer);
}
