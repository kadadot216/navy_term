#ifndef __INTERFACE_SIG_H__
#define __INTERFACE_SIG_H__

#include "signals.h"

void	sig_get_epid(int sig, siginfo_t *info, void *context);
void	sig_get_query(int sig, siginfo_t *info, void *context);
void	sig_get_response(int sig, siginfo_t *info, void *context);

#endif /* __INTERFACE_SIG_H__ */
