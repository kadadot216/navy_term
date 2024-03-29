#include "signals.h"

int	bit_retrieve_value(bit_t b, int n)
{
	if (b == 1)
		return (b << n);
	else if (b == 0)
		return (0);
	return (0);
}

bit_t	bit_from_sig(int signal)
{
	if (signal == SIGUSR2)
		return (1);
	return (0);
}
