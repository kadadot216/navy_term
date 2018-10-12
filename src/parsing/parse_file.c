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

	return (board_map_boat(this->board, *boat_ref, f_cell, l_cell));
}

int	game_parse_map(game_t *this, char const *filename)
{
	int	fd = 0;
	int	i = 0;
	char	line[BUFF_SIZE] = {'\0'};

	(void)this;
	fd = open(filename, OPEN_MODE);
	if (fd == -1)
		return (-1);
	while (read(fd, line, (sizeof(char) * BUFF_SIZE)) && i < PARSE_MAX) {
		if (game_map_boat(this, line) == -1) {
			return (-1);
		}
		i++;
	}
	fd = close(fd);
	return (1);
}
