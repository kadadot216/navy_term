#ifndef __QUERY_H__
#define __QUERY_H__

#include <sys/types.h>

void	send_query(int value, pid_t epid);
int	receive_query(void);
int	receive_connection_query(void);

#endif
