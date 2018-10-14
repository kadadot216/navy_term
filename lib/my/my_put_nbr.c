/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Displays the number given as a parameter.
*/

#include <unistd.h>

static	void	nbr_putchar(char const c)
{
	write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
	if (nb < 0) {
		nbr_putchar('-');
		nb = -nb;
	}
	if (nb / 10)
		my_put_nbr(nb / 10);
	nbr_putchar((nb % 10 + '0'));
	return (0);
}

