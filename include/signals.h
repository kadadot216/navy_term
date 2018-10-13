/*
** EPITECH PROJECT, 2018
** signals.h
** File description:
** Header file for signals queries and functions
*/

#ifndef __SIGNALS_H__
#define __SIGNALS_H__

typedef	unsigned char	bit_t;

typedef	struct s_sigquery {
	bit_t	header:2;
	bit_t	coords:6;
}	sigquery_t;

// PROMPT
char	*prompt_attack(char *buffer);

// SIGQUERY
sigquery_t	*sq_compose_query(sigquery_t *this, char *prompt);
int	sq_compose_nb(sigquery_t *this, char *prompt);	//DELET


#endif /* __SIGNALS_H__ */
