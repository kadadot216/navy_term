#include "my.h"
#include "navy.h"

game_t	*game_set_player(game_t *this, player_t player)
{
	this->me = player;
	return (this);
}

game_t	*game_set_role(game_t *this, role_t role)
{
	this->role = role;
	return (this);
}

game_t	*game_set_role_from_player(game_t *this)
{
	if (this->me == P1) {
		this = game_set_role(this, ROLE_PLAY);
	} else if (this->me == P2) {
		this = game_set_role(this, ROLE_WAIT);
	}
	return (this);
}

game_t	*game_set_board(game_t *this)
{
	board_init(this->board);
	return (this);
}

game_t	*game_set_lives(game_t *this)
{
	this->lives = LIVES;
	return (this);
}
