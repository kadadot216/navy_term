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
int	get_idx_from_coords(char *prompt)
{
	int	idx = 0;
	idx += (prompt[0] - 'A');
	printf("Encoded number: %d\n", idx);
	idx += ((prompt[1] - '1') * (1 << 3)); // or SIZE_X
	printf("Encoded number: %d\n", idx);
	return (idx);
}

// SEND CASE : "C2" => board[10] => case C2

// RECEIVE CASE : "C2" => (BigEnd) [00][010100] => Check at 10 => decypher => "C2"
char	*get_coords_from_idx(char *buffer, int idx)
{
	buffer[0] = idx % (1 << 3) + 'A';
	buffer[1] = idx / (1 << 3) + '1';
	return (buffer);
}

sigquery_t	*sq_compose_query(sigquery_t *this, char *prompt)
{
	int	bidx = 0;
	int	idx = 0;

	idx = get_idx_from_coords(prompt);
	while (bidx < 6) {
		this->coords = (idx % (1 << bidx));
		bidx++;
	}
	return (0);
}

void	sq_display_bitfield(sigquery_t *this)
{
	int	bidx = 0;

	while (bidx < 6) {
		printf("%d ", this->coords % (1 << bidx));
		bidx++;
	}
	printf("\n");
}
