void	my_memset(char *str, char c, unsigned int size)
{
	unsigned int	i = 0;

	while (i < size) {
		str[i] = c;
		i++;
	}
}
