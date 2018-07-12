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
#include "types.h"

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

int	is_ship_tag(char tag)
{
	return (tag >= '2' && tag <= '5');
}

int	check_delims_placement(char const *buffer)
{
	uint_t	line = 0;

	while (line < 32) {
		if (!(buffer[line + 1] == ':' && buffer[line + 4] == ':')) {
			return (0);
		}
		line += 8;
	}
	return (1);
}

int	is_al_chk(char const tag, char al_chk[])
{
	uint_t	i = 0;

	while (i < 4 && al_chk[i] != 0) {
		if (tag == al_chk[i]) {
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_ship_tokens(char const *buffer)
{
	uint_t	line = 0;
	uint_t	i = 0;
	char	al_chk[4] = {0};

	while (line < 32) {
		if (buffer[line] >= '2' && buffer[line] <= '5' &&
				is_al_chk(buffer[line], al_chk)) {

			al_chk[i] = buffer[line];
			i++;
			line += 8;
		}
		else {
			return (0);
		}
	}
	return (1);
}

char	*read_entries(char *buffer, char const *filepath)
{
	int	fd = 0;

	fd = open_file(filepath);
	if (fd == -1 || read(fd, buffer, 100) != 32) {
		close(fd);
		my_memset(buffer, '\0', 100);
		return (0);
	}
	close(fd);
	if (!(check_delims_placement(buffer) && check_ship_tokens(buffer))) {
		my_memset(buffer, '\0', 100);
		return (0);
	}
	return (buffer);
}
