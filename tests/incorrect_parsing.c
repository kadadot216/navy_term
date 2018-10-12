/*
** EPITECH PROJECT, 2018
** incorrect_parsing.c
** File description:
** UT for incorrect parsing
*/

#include "./include/unit_testing.h"
#include "./include/navy_test.h"

Test(incorrect_parsing, out_of_bounds_parsing)
{
	int	map_status = 1;

	board_t	board = {'0'};
	board_init(board);
	map_status = test_board_map_boat(board, '5', "F5", "F9");
	cr_assert_eq(map_status, -1);
}

Test(incorrect_parsing, wrong_boat_ref)
{
	int	map_status = 1;

	board_t	board = {'0'};
	board_init(board);
	map_status = test_board_map_boat(board, '4', "H1", "H3");
	cr_assert_eq(map_status, -1);
}

Test(incorrect_parsing, diagonal_parsing1)
{
	int	map_status = 1;

	board_t	board = {'0'};
	board_init(board);
	map_status = test_board_map_boat(board, '2', "C1", "B2");
	cr_assert_eq(map_status, -1);
}

Test(incorrect_parsing, cross_parsing)
{
	int	map_status = 1;

	board_t	board = {'0'};
	board_init(board);
	map_status = test_board_map_boat(board, '4', "C1", "C4");
	if (map_status == -1)
		test_fail();
	map_status = test_board_map_boat(board, '3', "B2", "D2");
	cr_assert_eq(map_status, -1);
}
