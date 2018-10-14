/*
** EPITECH PROJECT, 2018
** interface_act.h
** File description:
** Header file for Interface actions during runtime
*/

#ifndef __INTERFACE_ACT_H__
#define __INTERFACE_ACT_H__

#include "navy.h"
#include "signals.h"

// COM_INTERFACE_ACT
void	interface_act_set_pid(pid_t pid);
void	interface_act_reset_query(void);
void	interface_act_set_query(char *prompt);
void	interface_act_init(void);
void	interface_act_update_role(game_t *game);
void	interface_act_init_as(game_t *game);

// COM_INTERFACE_ACT2
void	interface_act_parse_pid(char const *arg);
void	interface_act_wait_for_p2pid(void);

// COM_INTERFACE_SIG
void	sig_get_p2pid(int sig, siginfo_t *info, void *context);

// DEBUG PRINT
void	db_interface_print_pid(void);
void	db_interface_print_query(void);
void	db_interface_print_header(void);
void	db_interface_print_role(void);
void	db_interface_print_connected(void);
void	db_interface_printall(void);


#endif /* __INTERFACE_ACT_H__ */
