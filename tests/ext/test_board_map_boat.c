/*
** EPITECH PROJECT, 2018
** test_board_map_boat.c
** File description:
** UT wrapper function for board_map_boat
*/

#include "my.h"
#include "navy.h"

int	test_board_map_boat(board_t this, char bref, char *first, char *last)
{
	int	map_status = 0;
	char	c1[3] = {'\0'};
	char	c2[3] = {'\0'};

	my_strncpy(c1, first, 2);
	my_strncpy(c2, last, 2);
	map_status = board_map_boat(this, bref, c1, c2);
	if (map_status == -1)
		return (-1);
	return (1);
}

