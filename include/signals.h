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

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

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
	pid_t		epid;
	sigaction_t	sig;
}	interface_t;

extern interface_t	com_interface;

#define	TIME_OUT	(120000000)
#define	WAIT_OFFSET	(30)
//#define	TIME_OUT	(1200000)

// INFO
void	print_my_pid(void);

// COM_INTERFACE
interface_t	*interface_init(interface_t *this);
interface_t	*interface_reset_query(interface_t *this);
interface_t	*interface_set_query(interface_t *this, char *prompt);
interface_t	*interface_set_pid(interface_t *this, pid_t pid);
interface_t	*interface_set_role(interface_t *this, int role);
interface_t	*interface_set_timeout(interface_t *this);
interface_t	*interface_set_connected(interface_t *this);
interface_t	*interface_set_disconnected(interface_t *this);

// PROMPT
char	*prompt_attack(char *buffer);

// DEBUG
void	sq_display_bitfield(sigquery_t *this);
void	sq_display_header(sigquery_t *this);

// SIGQUERY
sigquery_t	sq_new(void);
sigquery_t	*sq_compose_msg_query(sigquery_t *this, char *prompt);
sigquery_t	*sq_reset(sigquery_t *this);
int	sq_compose_nb(sigquery_t *this, char *prompt);	//DELET
char	*get_coords_from_idx(char *buffer, int idx);
int	message_retrieve_value(sigquery_t *this);
int	bit_retrieve_value(bit_t b, int n);


#endif /* __SIGNALS_H__ */
