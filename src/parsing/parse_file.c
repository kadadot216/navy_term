/*
** EPITECH PROJECT, 2018
** parse_file.c
** File description:
** Parse file function
*/

#include <unistd.h>
#include "navy.h"

#include <stdio.h>

int	game_map_boat(game_t *this, char *line)
{
	char	*boat_ref = &line[B_REF];
	char	*f_cell = &line[F_CELL];
	char	*l_cell = &line[L_CELL];
	char	*f_sep = &line[F_SEP];
	char	*l_sep = &line[L_SEP];
	char	*tail = &line[PARSE_TAIL];

	if (*f_sep != PARSE_SEP || *l_sep != PARSE_SEP || *tail != '\n')
		return (-1);
	return (board_map_boat(this->board, *boat_ref, f_cell, l_cell));
}

int	game_parse_map_fd(game_t *this, int const fd)
{
	int	i = 0;
	char	line[BUFF_SIZE] = {'\0'};

	while (read(fd, line, (sizeof(char) * BUFF_SIZE)) && i < PARSE_REQ) {
		if (game_map_boat(this, line) == -1) {
			return (-1);
		}
		i++;
	}
	if (i < PARSE_REQ)
		return (-1);
	return (1);
}

int	game_parse_map(game_t *this, char const *filename)
{
	int	fd = 0;

	fd = open(filename, OPEN_MODE);
	if (fd == -1 || (game_parse_map_fd(this, fd) == -1))
		return (-1);
	fd = close(fd);
	if (fd == -1)
		return (-1);
	return (1);
}
