/*
** EPITECH PROJECT, 2018
** interaction.c
** File description:
** Function interactions
*/

#include <sys/types.h>
#include <fcntl.h>
#include "my.h"
#include "stypes.h"

int	open_file(char const *filepath)
{
	int	fd = 0;

	fd = open(filepath, O_RDONLY);
	if (fd == -1) {
		my_puterror("Error during file opening");
		return (-1);
	}
	return (fd);
}

int	check_formats(char const *buffer)
{
	uint_t	y = 0;
	uint_t	x = 0;
}
