/*
** EPITECH PROJECT, 2018
** signals_testing.h
** File description:
** Header file for Functions prototypes for signal testing
*/

#ifndef __SIGNALS_TESTING_H__
#define __SIGNALS_TESTING_H__

#include "signals.h"

int	get_idx_from_coords(char *prompt);
char	*get_coords_from_idx(char *buffer, int idx);
sigquery_t	*set_message_bit(sigquery_t *this, int value);
sigquery_t	*sq_compose_msg_query(sigquery_t *this, char *prompt);
int	message_retrieve_value(sigquery_t *this);

#endif /* __SIGNALS_TESTING_H__ */

