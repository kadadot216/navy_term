#ifndef __UNIT_TESTING_H__
#define __UNIT_TESTING_H__

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

int	my_strtablen(char **av);
void	redirect_all_std(void);
void	test_fail(void);

#endif /* __UNIT_TESTING_H__ */
