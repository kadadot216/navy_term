#ifndef __MAIN_H__
#define __MAIN_H__

#include "navy.h"
#include "signals.h"
#include "interface_act.h"
#include "my.h"

game_t	*update_board(int index, game_t *game);
int	init_game(game_t *game, char **av);
int	navy_game(int ac, char **av);
void	play_game(game_t *game);
void	play_turn(game_t *game, board_t ennemy, char *prompt);
void	turn_attack(char *prompt, board_t enemy);
void	turn_wait(game_t *game);
void	game_display_boards(game_t *mine, board_t enemy);

#endif /* __MAIN_H__ */
