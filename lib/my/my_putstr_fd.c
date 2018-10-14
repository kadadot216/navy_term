#include <unistd.h>

int	my_putstr_fd(const int fd, const char *str)
{
	unsigned int	i = 0;

	while (str[i] != '\0')
		i++;
	write(fd, str, i);
	return (0);
}
