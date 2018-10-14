#include "./include/unit_testing.h"
#include "navy.h"

Test(argchecks, right_args_p1)
{
	int	status = 0;
	char	*argv[] = {"./navy", "pos", NULL};
	int	argc = my_strtablen(argv);

	status = check_for_help(argc, argv);
	cr_assert_eq(status, 0);
	status = navy_argchecks(argc, argv);
	cr_assert_eq(status, 1);
}

Test(argchecks, right_args_p2)
{
	int	status = 0;
	char	*argv[] = {"./navy", "24242", "pos", NULL};
	int	argc = my_strtablen(argv);

	status = check_for_help(argc, argv);
	cr_assert_eq(status, 0);
	status = navy_argchecks(argc, argv);
	cr_assert_eq(status, 1);
}

Test(argchecks, wrong_args_p2_not_pid)
{
	int	status = 0;
	char	*argv[] = {"./navy", "2a242", "pos", NULL};
	int	argc = my_strtablen(argv);

	status = check_for_help(argc, argv);
	cr_assert_eq(status, 0);
	status = navy_argchecks(argc, argv);
	cr_assert_eq(status, 0);
}

Test(argchecks, search_help_as_arg2)
{
	int	status = 0;
	char	*argv[] = {"./navy", "23242", "-h", NULL};
	int	argc = my_strtablen(argv);

	status = check_for_help(argc, argv);
	cr_assert_eq(status, 1, "Got %d", status);
	status = navy_argchecks(argc, argv);
	cr_assert_eq(status, 1, "Got %d", status);
}

Test(argchecks, search_help_as_arg1)
{
	int	status = 0;
	char	*argv[] = {"./navy", "-h", "pos", NULL};
	int	argc = my_strtablen(argv);

	status = check_for_help(argc, argv);
	cr_assert_eq(status, 1, "Got %d", status);
	status = navy_argchecks(argc, argv);
	cr_assert_eq(status, 0, "Got %d", status);
}
