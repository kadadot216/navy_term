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

#define	BASE_2	(2)

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

sigquery_t	*sq_compose_query(sigquery_t *this, char *prompt)
{
	int	idx = 0;

	idx = get_idx_from_coords(prompt);
	this = set_message_bit(this, idx);
	return (0);
}

int	add_bit_to_value(bit_t b, int n)
{
	if (b == 1)
		return (b << n);
	else if (b == 0)
		return (0);
	return (0);
	
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
