#ifndef __MAIN_H__
#define __MAIN_H__

#include "types.h"

navy_game_t	*init_game(navy_game_t *game, char const *filepath);
navy_game_t	*destroy_game(navy_game_t *game);
void		play_game(navy_game_t *game);

#endif

