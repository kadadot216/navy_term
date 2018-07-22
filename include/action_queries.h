#ifndef __ACTION_QUERIES_H__
#define __ACTION_QUERIES_H__

#include "types.h"

void		dispatch_response_query(navy_game_t *game, parser_t *prompt);
void		send_attack_query(parser_t *prompt, pid_t epid);
parser_t	receive_attack_query(void);
navy_game_t	*send_attack_response(parser_t *p, navy_game_t *game,
		pid_t epid);

#endif
