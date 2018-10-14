/*
** EPITECH PROJECT, 2018
** retrieve_idx_from_bits.c
** File description:
** Retrieve idx from bits TUs
*/

#include "navy.h"
#include "./include/signals_testing.h"
#include "./include/unit_testing.h"

Test(ret_idx_f_bits, ret_idx_f_bits1)
{
	int	res = 0;

	sigquery_t	query = sq_new();
	sq_compose_msg_query(&query, "B1");
	res = message_retrieve_value(&query);
	cr_assert_eq(res, 1);
}

Test(ret_res_f_bits, ret_res_f_bits2)
{
	int	res = 0;

	sigquery_t	query = sq_new();
	sq_compose_msg_query(&query, "G5");
	res = message_retrieve_value(&query);
	cr_assert_eq(res, 38);
}

Test(ret_res_f_bits, ret_res_f_bits3)
{
	int	res = 0;

	sigquery_t	query = sq_new();
	sq_compose_msg_query(&query, "H8");
	res = message_retrieve_value(&query);
	cr_assert_eq(res, 63);
}

Test(ret_res_f_bits, ret_res_f_bits4)
{
	int	res = 0;

	sigquery_t	query = sq_new();
	sq_compose_msg_query(&query, "F3");
	res = message_retrieve_value(&query);
	cr_assert_eq(res, 21);
}

Test(ret_res_f_bits, ret_res_f_bits5)
{
	int	res = 0;

	sigquery_t	query = sq_new();
	sq_compose_msg_query(&query, "D6");
	res = message_retrieve_value(&query);
	cr_assert_eq(res, 43);
}
