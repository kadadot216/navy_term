/*
** EPITECH PROJECT, 2018
** running.c
** File description:
** Game running related functions
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "types.h"
#include "game.h"

board_type_t	change_turn(board_type_t turn)
{
	return ((turn + 1) % 2);
}

void	check_for_winner(board_type_t turn, navy_game_t *game)
{
	if (game->total_hits[turn] == 0) {
		game->status = turn + 2;
	}
}

void	display_winner_msg(game_status_t status)
{
	if (status == ME_WON) {
		my_putstr_fd(1, "I won");
	} else if (status == ENEMY_WON) {
		my_putstr_fd(1, "Enemy won");
	}
}

int	prompt_valid_attack(char const *prompt)
{
	if (my_strlen(prompt) != 3) {
		my_putstr_fd(2, "wrong position\n");
		return (0);
	} else if (!((prompt[0] >= 'A' && prompt[0] <= 'H') && (prompt[1] >= '1' && prompt[1] <= '8'))) {
		my_putstr_fd(2, "wrong position\n");
		return (0);
	}
	return (1);
}

int	prompt_instruction(parser_t *parser)
{
	char	prompt[1000] = {0};

	my_putstr_fd(1, "attack: ");
	while (!(read(0, prompt, 1000)) || !(prompt_valid_attack(prompt))) {
		my_putstr_fd(1, "attack: ");
	}
	parser->x = prompt[0] - 'A';
	parser->y = prompt[1] - '1';
	return (1);
}

void	display_attack_msg(parser_t *p)
{
	my_putchar(p->x + 'A');
	my_putchar(p->y + '1');
	my_putstr_fd(1, ": ");
}

int	dispatch_instruction(parser_t *p, board_t **board)
{
	display_attack_msg(p);
	if (board[p->y][p->x] == NONE) {
		board[p->y][p->x] = MISSED;
		my_putstr_fd(1, "missed\n\n");
		return (0);
	} else if (board[p->y][p->x] >= L2 && board[p->y][p->x] <= L5) {
		board[p->y][p->x] = HIT;
		my_putstr_fd(1, "hit\n\n");
		return (1);
	}
	return (0);
}

void	display_game(navy_game_t *game)
{
	my_putstr_fd(1, "my positions:\n");
	display_board(game->boards[MINE]);
	my_putstr_fd(1, "enemy's positions:\n");
	display_board(game->boards[ENEMY]);
	my_putstr_fd(1, "\n");
}

void	play_game(navy_game_t *game)
{
	board_type_t	turn = MINE;
	parser_t	prompt;

	while (game->status == RUNNING)	{
		display_game(game);
		prompt_instruction(&prompt);
		game->total_hits[turn] -= dispatch_instruction(&prompt, game->boards[turn]);
		check_for_winner(turn, game);
		turn = change_turn(turn);
	}
	display_winner_msg(game->status);
}
