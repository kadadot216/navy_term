/*
** EPITECH PROJECT, 2018
** file_parsing.c
** File description:
** File parsing tests
*/

#include "navy.h"
#include "./include/unit_testing.h"

Test(file_parsing, correct_file1, .init=redirect_all_std)
{
	game_t	game = game_setup(P1);
	int	parsing_status = 0;

	parsing_status = game_parse_map(&game, "./tests/data/pos1");
	cr_assert_eq(parsing_status, 1);
}

Test(file_parsing, missing_file, .init=redirect_all_std)
{
	game_t	game = game_setup(P1);
	int	parsing_status = 0;

	parsing_status = game_parse_map(&game, NULL);
	cr_assert_eq(parsing_status, -1);
}

Test(file_parsing, missing_lines, .init=redirect_all_std)
{
	game_t	game = game_setup(P1);
	int	parsing_status = 0;

	parsing_status = game_parse_map(&game, "./tests/data/mislines");
	cr_assert_eq(parsing_status, -1);
}

Test(file_parsing, typo_in_file, .init=redirect_all_std)
{
	game_t	game = game_setup(P1);
	int	parsing_status = 0;

	parsing_status = game_parse_map(&game, "./tests/data/typo");
	cr_assert_eq(parsing_status, -1);
}

Test(file_parsing, empty_file, .init=redirect_all_std)
{
	game_t	game = game_setup(P1);
	int	parsing_status = 0;

	parsing_status = game_parse_map(&game, "./tests/data/empty");
	cr_assert_eq(parsing_status, -1);
}
