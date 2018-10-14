#include "navy.h"
#include "signals.h"

interface_t	*interface_set_connected(interface_t *this)
{
	this->connected = 1;
	return (this);
}

interface_t	*interface_set_disconnected(interface_t *this)
{
	this->connected = 0;
	return (this);
}

interface_t	*interface_set_timeout(interface_t *this)
{
	this->timeout = 1;
	return (this);
}

interface_t	*interface_set_role(interface_t *this, int role)
{
	this->role = (irole_t)role;
	return (this);
}

interface_t	*interface_map_query(interface_t *this, int *sigfield)
{
	this->uquery.h1 = bit_from_sig(sigfield[0]);
	this->uquery.h2 = bit_from_sig(sigfield[1]);
	this->uquery.c1 = bit_from_sig(sigfield[2]);
	this->uquery.c2 = bit_from_sig(sigfield[3]);
	this->uquery.c3 = bit_from_sig(sigfield[4]);
	this->uquery.c4 = bit_from_sig(sigfield[5]);
	this->uquery.c5 = bit_from_sig(sigfield[6]);
	this->uquery.c6 = bit_from_sig(sigfield[7]);
	return (this);
}
