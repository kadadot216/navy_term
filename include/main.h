#ifndef __MAIN_H__
#define __MAIN_H__

#include "types.h"

navy_game_t	*destroy_game(navy_game_t *game);
int		play_game(navy_game_t *game);
int		check_for_help(int ac, char **av);
navy_game_t	*init_game_as(navy_game_t *game, int ac, char **av);

#endif

