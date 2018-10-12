/*
** EPITECH PROJECT, 2018
** board_mapping.c
** File description:
** Board mapping UT file
*/

#include "./include/unit_testing.h"
#include "./include/navy_test.h"
#include "my.h"

Test(board_mapping, empty_board, .init=redirect_all_std)
{
	char	*buffer = "........\n........\n........\n........\n"
		"........\n........\n........\n........\n\n";

	board_t	board = {'0'};
	board_init(board);
	fflush(stdout);
	debug_board_display(board);
	cr_assert_stdout_eq_str(buffer, "");
}

Test(board_mapping, setting_coords1, .init=redirect_all_std)
{
	char	*buffer = "........\n........\n..2.....\n..2.....\n........\n"
		"........\n........\n........\n\n";
	int	map_status = 0;

	board_t	board = {'0'};
	board_init(board);
	map_status = test_board_map_boat(board, '2', "C3", "C4");
	if (map_status < 1)
		test_fail();
	fflush(stdout);
	debug_board_display(board);
	cr_assert_stdout_eq_str(buffer, "");
}

Test(board_mapping, setting_coords3, .init=redirect_all_std)
{
	char	*buffer = "333.....\n........\n..2.....\n..2.....\n........\n"
		"........\n........\n........\n\n";
	int	map_status = 1;

	board_t	board = {'0'};
	board_init(board);
	map_status = test_board_map_boat(board, '2', "C3", "C4");
	map_status += test_board_map_boat(board, '3', "C1", "A1");
	if (map_status < 2)
		test_fail();
	fflush(stdout);
	debug_board_display(board);
	cr_assert_stdout_eq_str(buffer, "");
}

Test(board_mapping, setting_coords4, .init=redirect_all_std)
{
	char	*buffer = "..2.....\n..2.....\n........\n...333..\n.4......\n"
		".4......\n.4.55555\n.4......\n\n";
	int	map_status = 1;

	board_t	board = {'0'};
	board_init(board);
	map_status = test_board_map_boat(board, '2', "C2", "C1");
	map_status += test_board_map_boat(board, '3', "D4", "F4");
	map_status += test_board_map_boat(board, '4', "B8", "B5");
	map_status += test_board_map_boat(board, '5', "D7", "H7");
	if (map_status < 4)
		test_fail();
	fflush(stdout);
	debug_board_display(board);
	cr_assert_stdout_eq_str(buffer, "");
}
