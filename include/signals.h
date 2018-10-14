/*
** EPITECH PROJECT, 2018
** signals.h
** File description:
** Header file for signals queries and functions
*/

#ifndef __SIGNALS_H__
#define __SIGNALS_H__

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

#define	TIME_OUT	(120000000)
#define	WAIT_OFFSET	(100)
#define	BASE_2	(2)

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

typedef struct sigaction	sigaction_t;

typedef enum	e_irole {
	I_PLAY,
	I_WAIT
}	irole_t;

typedef struct	s_interface {
	bit_t		connected:1;
	bit_t		timeout:1;
	irole_t		role;
	sigquery_t	uquery;
	unsigned int	bc;
	unsigned int	signal;
	pid_t		epid;
	sigaction_t	sig;
}	interface_t;

extern interface_t	com_interface;

bit_t	bit_from_sig(int signal);
char	*get_coords_from_idx(char *buffer, int idx);
char	*prompt_attack(char *buffer);
int	bit_retrieve_value(bit_t b, int n);
int	message_retrieve_value(sigquery_t *this);
int	sq_header_check_hit(sigquery_t *this);
int	sq_header_is_msg(sigquery_t *this);
interface_t	*interface_init(interface_t *this);
interface_t	*interface_init_sig(interface_t *this);
interface_t	*interface_map_query(interface_t *this, int *sigfield);
interface_t	*interface_reset_query(interface_t *this);
interface_t	*interface_set_connected(interface_t *this);
interface_t	*interface_set_disconnected(interface_t *this);
interface_t	*interface_set_pid(interface_t *this, pid_t pid);
interface_t	*interface_set_query(interface_t *this, char *prompt);
interface_t	*interface_set_role(interface_t *this, int role);
interface_t	*interface_set_timeout(interface_t *this);
sigquery_t	*sq_compose_msg_query(sigquery_t *this, char *prompt);
sigquery_t	*sq_cut_connection(sigquery_t *this);
sigquery_t	*sq_header_set_cut(sigquery_t *this);
sigquery_t	*sq_header_set_msg(sigquery_t *this);
sigquery_t	*sq_header_set_response(sigquery_t *this, int hit);
sigquery_t	*sq_reset(sigquery_t *this);
sigquery_t	sq_new(void);
void	print_my_pid(void);
void	sq_display_bitfield(sigquery_t *this);
void	sq_display_header(sigquery_t *this);

#endif /* __SIGNALS_H__ */
