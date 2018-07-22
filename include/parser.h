/*
** EPITECH PROJECT, 2018
** parser.h
** File description:
** Header file for parser.c
*/

#ifndef __PARSER_H__
#define __PARSER_H__

#include "types.h"

uint_t	parser_is_line_valid(char *line, parser_t *c);
int	parser_parse_file(board_t **board, char const *filepath);
board_t	**parser_line_to_board(board_t **board, parser_t *c, uint_t offset);

#endif
