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
	bit_t	h1:1;
	bit_t	h2:1;
	bit_t	c1:1;
	bit_t	c2:1;
	bit_t	c3:1;
	bit_t	c4:1;
	bit_t	c5:1;
	bit_t	c6:1;
}	sigquery_t;

#define	BASE_2	(2)

// PROMPT
char	*prompt_attack(char *buffer);

// DEBUG
void	sq_display_bitfield(sigquery_t *this);

// SIGQUERY
sigquery_t	sq_new(void);
sigquery_t	*sq_compose_msg_query(sigquery_t *this, char *prompt);
int	sq_compose_nb(sigquery_t *this, char *prompt);	//DELET
char	*get_coords_from_idx(char *buffer, int idx);
int	message_retrieve_value(sigquery_t *this);
int	bit_retrieve_value(bit_t b, int n);


#endif /* __SIGNALS_H__ */
