/*
** EPITECH PROJECT, 2018
** file_parsing2.c
** File description:
** File parsing tests
*/

#include "navy.h"
#include "./include/unit_testing.h"

Test(file_parsing, different_seps, .init=redirect_all_std)
{
	game_t	game = game_setup(P1);
	int	parsing_status = 0;

	parsing_status = game_parse_map(&game, "./tests/data/oseps");
	cr_assert_eq(parsing_status, -1);
}

Test(file_parsing, unordered_boats, .init=redirect_all_std)
{
	game_t	game = game_setup(P1);
	int	parsing_status = 0;

	parsing_status = game_parse_map(&game, "./tests/data/unordered");
	cr_assert_eq(parsing_status, 1);
}
