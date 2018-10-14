/*
** EPITECH PROJECT, 2018
** com_interface_act2.c
** File description:
** Interface actions part.2
*/

#include "navy.h"
#include "my.h"
#include "interface_act.h"

interface_t	interface;

void	interface_act_parse_pid(char const *arg)
{
	interface_act_set_pid((pid_t) (my_getnbr(arg)));
}

void	interface_act_wait_for_p2pid(void)
{

}
