#include "macros.h"
#include "parser_check.h"
#include "types.h"

static parser_t	map_parser(parser_t *c, char *line)
{
	c->x = (int) line[0];
	c->y = (int) line[1];
	c->x -= 'A';
	c->y -= '1';
	return (*c);
}

uint_t	parser_is_line_valid(char *line, parser_t *c)
{
	uint_t	offset = 0;

	if (line[1] != ':' || line[4] != ':') {
		return (0);
	}
	if (line[7] != '\n' && line [7] != '\0') {
		return (0);
	}
	if (!(line[0] >= L2 && line[0] <= L5)) {
		return (0);
	}
	c[0] = map_parser(&c[0], &line[2]);
	c[1] = map_parser(&c[1], &line[5]);
	offset = (line[0] - '1');
	if (!(parser_is_valid(c, offset)))
		return (0);
	return (offset);
}

board_t	**parser_line_to_board(board_t **board, parser_t *c, uint_t offset)
{
	int	x1 = LOWEST(c[0].x, c[1].x);
	int	x2 = HIGHEST(c[0].x, c[1].x);
	int	y1 = LOWEST(c[0].y, c[1].y);
	int	y2 = HIGHEST(c[0].y, c[1].y);
	int	x = x1;
	int	y = y1;

	while (x <= x2) {
		board[y1][x] = (offset + '1');
		x++;
	}
	while (y <= y2) {
		board[y][x1] = (offset + '1');
		y++;
	}
	return (board);
}
