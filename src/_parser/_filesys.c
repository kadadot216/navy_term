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
#include "parser.h"
#include "types.h"
#include "defs.h"


int	parser_read_entries(char *buffer, char const *filepath)
{
	int	fd = 0;

	fd = open(filepath, O_RDONLY);
	if (fd == -1 || read(fd, buffer, BUFFLEN) != BUFFLEN) {
		my_memset(buffer, '\0', BUFFLEN);
		return (0);
	}
	buffer[BUFFLEN - 1] = '\0';
	close(fd);
	return (1);
}

int	parser_parse_file(board_t **board, char const *filepath)
{
	char	buffer[BUFFLEN] = { '\0' };
	uid_t	line = 0;
	parser_t	coords[2];
	int	offset = 0;

	if (!parser_read_entries(buffer, filepath)) {
		my_putstr_fd(2, "File format is not respected!\n");
		return (0);
	}
	while (line < NB_BOATS) {
		if (!(offset = parser_is_line_valid(BOARD_LINE, coords))) {
			return (0);
		}
		board = parser_line_to_board(board, coords, offset);
		line++;
	}
	return (1);
}
