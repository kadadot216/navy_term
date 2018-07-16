#ifndef __BOARD_H__
#define __BOARD_H__

#include "types.h"

board_cell_t	**init_board(armada_t *armada);
board_cell_t	**unset_board(board_cell_t **table);

#endif
