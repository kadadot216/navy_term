#include "macros.h"
#include "my.h"
#include "types.h"

int	in_bounds(parser_t *c)
{
	return ((c->x >= 0 && c->x <= 7) && (c->y >= 0 && c->y <= 7));
}

int	parser_is_valid(parser_t *c, int offset)
{
	if (!(in_bounds(&c[0]) && in_bounds(&c[1]))) {
		my_putstr_fd(2, "descriptor: Out of bounds\n");
		return (0);
	}
	if (ABS((c[1].x - c[0].x)) == offset && (c[1].y - c[0].y) == 0) {
		return (1);
	}
	if (ABS((c[1].y - c[0].y)) == offset && (c[1].x - c[0].x) == 0) {
		return (1);
	}
	return (0);

}
