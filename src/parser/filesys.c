#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "types.h"
#include "defs.h"

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

int	parser_is_valid(parser_t *p)
{
	if (!(p->p1[0] >= 0 && p->p1[0] <= 7 && p->p2[1] >= 0 && p->p2[1] <= 7)) {
		my_putstr_fd(2, "descriptor: Wrong boat size\n");
		return (0);
	}
	if (p->p1[1] + p->offset_x == p->p2[1] || p->p1[1] - p->offset_x == p->p2[1]) {
		p->offset_y = p->offset_x;
		p->offset_x = 0;
		return (1);
	}
	if (p->p1[0] + p->offset_x == p->p2[0] || p->p1[0] - p->offset_x == p->p2[0])
		return (1);
	return (0);

}

int	abs(int n)
{
	return ((n < 0) ? (- n) : n);
}

int	offset_is_valid(parser_t *p)
{
	if ((p->lab - '1') == abs(p->p2[1] - p->p1[1]))
		return (1);
	if ((p->lab - '1') == abs(p->p2[0] - p->p1[0]))
		return (1);
	return (0);
}

parser_t	*map_pts(parser_t *p, char *line)
{
	my_strncpy(p->p1, &line[2], 2);
	my_strncpy(p->p2, &line[5], 2);
	p->p1[0] -= 'A';
	p->p1[1] -= '1';
	p->p2[0] -= 'A';
	p->p2[1] -= '1';
	return (p);
}

int	parser_is_line_valid(char *line, int size, parser_t *p)
{
	if (line[1] != ':' || line[4] != ':') {
		return (0);
	}
	if (line[7] != '\n' && line [7] != '\0') {
		return (0);
	}
	if (!(line[0] >= L2 && line[0] <= L5)) {
		return (0);
	}
	p->lab = line[0];
	p = map_pts(p, line);
	if (!offset_is_valid(p))
		return (0);
	p->offset_x = abs(p->p2[0] - p->p1[0]);
	p->offset_y = abs(p->p2[1] - p->p1[1]);
	if (!parser_is_valid(p)) {
		return (0);
	}
	return (1);
}

board_t	**parser_line_to_board(board_t **board, parser_t *parser)
{ 
	int	x = parser->p1[0];
	int	y = parser->p1[1];
	int	off = 0;

	off = parser->offset_x;
	while (off >= 0) {
		board[y][x + off] = parser->lab;
		off--;
	}
	off = parser->offset_y;
	while (off >= 0) {
		board[y + off][x] = parser->lab;
		off--;
	}
	return (board);
}

int	parser_parse_file(board_t **board, char const *filepath)
{
	char	buffer[BUFFLEN] = { '\0' };
	uid_t	line = 0;
	parser_t	line_p;

	if (!parser_read_entries(buffer, filepath)) {
		my_putstr_fd(2, "File format is not respected!\n");
		return (0);
	}
	while (line < NB_BOATS) {
		if (!parser_is_line_valid(BOARD_LINE, LINELEN, &line_p)) {
			return (0);
		}
		board = parser_line_to_board(board, &line_p);
		line++;
	}
	return (1);
}
