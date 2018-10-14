int	my_strtablen(char **tab)
{
	int	len = 0;

	while (tab[len] != 0)
		len++;
	return (len);
}
