#include <unistd.h>

void	my_puterror(char *strerr)
{
	int	i = 0;

	while (strerr[i] != '\0')
		i++;
	write(2, strerr, i);
}
