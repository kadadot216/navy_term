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

sigquery_t	*sq_header_set_msg(sigquery_t *this)
{
	this->h1 = 0;
	this->h2 = 1;
	return (this);
}

sigquery_t	*sq_header_set_response(sigquery_t *this, int hit)
{
	this->h1 = 1;
	this->h2 = hit;
	return (this);
}
