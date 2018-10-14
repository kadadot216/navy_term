#include "my.h"
#include "navy.h"

game_t	game_setup(player_t player)
{
	game_t	new;
	game_set_player(&new, player);
	game_set_role_from_player(&new);
	game_set_board(&new);
	game_set_lives(&new);
	return (new);
}

game_t	*game_unset(game_t *this)
{
	this = game_set_board(this);
	this->lives = 0;
	this->me = 0;
	this->role = 0;
	return (this);
}
