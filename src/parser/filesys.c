/*
** EPITECH PROJECT, 2018
** filesys.c
** File description:
** Function interactions
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "types.h"
#include "defs.h"

int	open_file(char const *filepath)
{
	int	fd = 0;

	fd = open(filepath, O_RDONLY);
	if (fd == -1) {
		my_putstr_fd(2, "Error during file opening\n");
		return (-1);
	}
	return (fd);
}

int	read_entries(char *buffer, char const *filepath)
{
	int	fd = 0;

	fd = open_file(filepath);
	if (fd == -1 || read(fd, buffer, BUFFLEN) != BUFFLEN) {
		my_memset(buffer, '\0', BUFFLEN);
		return (0);
	}
	buffer[BUFFLEN - 1] = '\0';
	close(fd);
	return (1);
}

int	parse_file(char const *filepath)
{
	char	buffer[BUFFLEN] = { '\0' };
	uid_t	line = 0;

	if (!read_entries(buffer, filepath)) {
		my_putstr_fd(2, "File format is not respected!\n");
		return (0);
	}
	while (line < BUFFLEN) {
		parse_line_to_board(&buffer[line * LINELEN], )
		line++;
	}
	return (1);
}
