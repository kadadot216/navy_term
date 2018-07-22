#include "my.h"
#include "types.h"

extern	com_interface_t	iface;

int	get_p1pid(char const *arg)
{
	int	i = 0;

	while (arg[i] != '\0') {
		if (!(arg[i] >= '0' && arg[i] <= '9')) {
			return (0);
		}
		iface.epid *= 10;
		iface.epid += (arg[i] - '0');
		i++;
	}
	return (1);
}

int	check_for_help(int ac, char **av)
{
	uint_t	i = 0;

	while (i < (uint_t) ac) {
		if (my_strcmp(av[i], "-h") == 0) {
			return (1);
		}
		i++;
	}
	return (0);
}
