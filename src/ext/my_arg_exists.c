/*
** EPITECH PROJECT, 2018
** my_arg_exists.c
** File description:
** Checks wheter an argument exists or not
*/

#include <stdio.h>

int	my_arg_exists(char const *arg)
{
	return ((arg != NULL) && (arg[0] != '\0'));
}
