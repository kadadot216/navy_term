#include "navy.h"

game_t	*game_update_role(game_t *this)
{
	if (this->role == ROLE_PLAY)
		this = game_set_role(this, ROLE_WAIT);
	else if (this->role == ROLE_WAIT)
		this = game_set_role(this, ROLE_PLAY);
	return (this);
}
