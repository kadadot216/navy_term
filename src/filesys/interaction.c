/*
** EPITECH PROJECT, 2018
** interaction.c
** File description:
** Function interactions
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
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

int	check_format(char const *buffer, int rstat)
{
	if (rstat > 32) {
		return (-1);
	}
}

int	read_entries(char const *filepath)
{
	char	buffer[100] = { 0 };
	int	fd = 0;
	int	cstat = 0;

	fd = open_file(filepath);
	if (fd == -1) {
		close(fd);
		return (-1);
	}
	cstat = read(fd, buffer, 100);
	close(fd);
	cstat = check_format(buffer, cstat);
	return (cstat);
}
