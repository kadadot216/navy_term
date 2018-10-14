#include <stdio.h>

int	my_arg_exists(char const *arg)
{
	return ((arg != NULL) && (arg[0] != '\0'));
}
