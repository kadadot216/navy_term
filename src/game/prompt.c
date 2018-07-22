#include <unistd.h>
#include "types.h"
#include "my.h"

static int	prompt_in_board(char let, char nb)
{
	return (let >= 'A' && let <= 'H' && nb >= '1' && nb <= '8');
}

static int	prompt_valid_attack(char *prompt)
{
	if (!prompt[0]) {
		return (0);
	} else if (my_strlen(prompt) > 3) {
		my_putstr_fd(2, "wrong position\n");
		return (0);
	} else if (!(prompt_in_board(prompt[0], prompt[1]))) {
		my_putstr_fd(2, "wrong position\n");
		return (0);
	}
	return (1);
}

int	prompt_instruction(parser_t *parser)
{
	char	prompt[100] = {'\0'};

	while (!(prompt_valid_attack(prompt))) {
		my_putstr_fd(1, "attack: ");
		my_memset(prompt, '\0', 100);
		read(0, prompt, 100);
	}
	parser->x = prompt[0] - 'A';
	parser->y = prompt[1] - '1';
	return (1);
}
