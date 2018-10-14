#include "./include/unit_testing.h"
#include "navy.h"

Test(game_init, init_as_p1)
{
	game_t	p1 = game_setup(P1);

	cr_assert_eq(p1.lives, 14);
	cr_assert_eq(p1.role, ROLE_PLAY);
	cr_assert_eq(p1.me, P1);
}

Test(game_init, init_as_p2)
{
	game_t	p2 = game_setup(P2);

	cr_assert_eq(p2.lives, 14);
	cr_assert_eq(p2.role, ROLE_WAIT);
	cr_assert_eq(p2.me, P2);
}
