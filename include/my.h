/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Header file for my libs
*/

#ifndef __MY_H__
#define __MY_H__

void	my_putstr_fd(int const fd, char const *str);
void	my_puterror(char const *strerr);
void	my_memset(char *str, char c, unsigned int size);
void	my_putchar(char const c);
void	my_putcharx_fd(int fd, char c, int times);
char	*my_strncpy(char *dest, char const *src, int n);

#endif
