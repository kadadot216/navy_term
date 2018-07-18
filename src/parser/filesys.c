#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "types.h"
#include "defs.h"

#define	ABS(x) ((x < 0) ? (-x) : (x))
#define	HIGHEST(x, y)	((x > y) ? x : y)
#define	LOWEST(x, y)	((x > y) ? y : x)

int	open_file(char const *filepath)
{
	int	fd = 0;

	fd = open(filepath, O_RDONLY);
	if (fd == -1) {
		my_putstr_fd(2, "Error during file opening\n");
		return (-1);
	}
	return (fd);
}

int	parser_read_entries(char *buffer, char const *filepath)
{
	int	fd = 0;

	fd = open_file(filepath);
	if (fd == -1 || read(fd, buffer, BUFFLEN) != BUFFLEN) {
		my_memset(buffer, '\0', BUFFLEN);
		return (0);
	}
	buffer[BUFFLEN - 1] = '\0';
	close(fd);
	return (1);
}

int	in_bounds(parser_t *c)
{
	return ((c->x >= 0 && c->x <= 7) && (c->y >= 0 && c->y <= 7));
}

int	parser_is_valid(parser_t *c, uint_t offset)
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

parser_t	map_parser(parser_t *c, char *line)
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

int	parser_parse_file(board_t **board, char const *filepath)
{
	char	buffer[BUFFLEN] = { '\0' };
	uid_t	line = 0;
	parser_t	coords[2];
	uint_t	offset = 0;

	if (!parser_read_entries(buffer, filepath)) {
		my_putstr_fd(2, "File format is not respected!\n");
		return (0);
	}
	while (line < NB_BOATS) {
		if (!(offset = parser_is_line_valid(BOARD_LINE, coords))) {
			return (0);
		}
		board = parser_line_to_board(board, coords, offset);
		line++;
	}
	return (1);
}
