int	my_strlen(char const *str)
{
	int	str_count = 0;

	while (*str != '\0') {
		str_count++;
		str++;
	}
	return (str_count);
}
