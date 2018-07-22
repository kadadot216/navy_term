/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** prompt related functions
*/

#include <unistd.h>
#include "types.h"
#include "my.h"

static int	prompt_valid_attack(char *prompt)
{
	if (!prompt[0]) {
		return (0);
	} else if (my_strlen(prompt) != 3) {
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
	char	prompt[4];

	while (!(prompt_valid_attack(prompt))) {
		my_putstr_fd(1, "attack: ");
		my_memset(prompt, '\0', 4);
		read(0, prompt, 3);
		prompt[3] = 0;
	}
	parser->x = prompt[0] - 'A';
	parser->y = prompt[1] - '1';
	return (1);
}
