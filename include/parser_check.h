#ifndef __PARSER_CHECK_H__
#define __PARSER_CHECK_H__

#include "types.h"

int	in_bounds(parser_t *c);
int	parser_is_valid(parser_t *c, uint_t offset);

#endif
