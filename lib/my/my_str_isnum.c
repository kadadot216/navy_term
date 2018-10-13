/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** Check wheter a string contains only numerals
*/

int	my_char_isnum(char const c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	else
		return (0);
}

int	my_str_isnum(char const *str)
{
	int	i = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0') {
		if (!(my_char_isnum(str[i])))
			return (0);
		else
			i++;
	}
	return (1);
}
