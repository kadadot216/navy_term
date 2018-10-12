/*
** EPITECH PROJECT, 2018
** test_fail.c
** File description:
** Function that fails a test on purpose
*/

#include "../include/unit_testing.h"

void	test_fail(void)
{
	cr_assert_eq(0, 1);
}
