#include <unistd.h>
#include "my.h"
#include "types.h"
#include "messages.h"
#include "query.h"

void	send_attack_query(parser_t *prompt, pid_t epid)
{
	int	pos_x = prompt->x + 1;
	int	pos_y = prompt->y + 1;

	send_query(pos_x, epid);
	usleep(30);
	send_query(pos_y, epid);
	usleep(30);
}

void	dispatch_response_query(navy_game_t *game, parser_t *prompt)
{
	int	hit = receive_query();

	display_attack_msg(prompt);
	if (hit == 2) {
		game->boards[1][prompt->y][prompt->x] = HIT;
		game->total_hits[1]--;
		my_putstr_fd(1, "hit\n\n");
	} else if (hit == 1) {
		game->boards[1][prompt->y][prompt->x] = MISSED;
		my_putstr_fd(1, "missed\n\n");
	}
}

parser_t	receive_attack_query(void)
{
	parser_t	query = {0, 0};

	my_putstr_fd(1, "\nwaiting for enemy's attack...\n");
	query.x = (receive_query() - 1);
	query.y = (receive_query() - 1);
	return (query);
}

navy_game_t	*send_attack_response(parser_t *p, navy_game_t *game,
		pid_t epid)
{
	board_t	*position = &game->boards[0][p->y][p->x];

	display_attack_msg(p);
	if (*position >= L2 && *position <= L5) {
		game->boards[0][p->y][p->x] = HIT;
		game->total_hits[0]--;
		send_query(2, epid);
		my_putstr_fd(1, "hit\n\n");
	} else if (*position == NONE) {
		*position = MISSED;
		send_query(1, epid);
		my_putstr_fd(1, "missed\n\n");
	}
	return (game);
}
