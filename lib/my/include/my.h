#ifndef __MY_H__
#define __MY_H__

void	my_putstr_fd(int const fd, char const *str);
void	my_puterror(char const *strerr);
void	my_memset(char *str, char c, unsigned int size);
void	my_putchar(char const c);
void	my_putcharx_fd(int fd, char c, int times);
void	my_put_nbr(int nb);
int	my_getnbr(char const *str);
int	my_str_isnum(char const *str);
int	my_getnbr(char const *str);
int	my_arg_exists(char const *arg);
int	my_strlen(char const *str);
int	my_strcmp(char const *s1, char const *s2);
char	*my_strncpy(char *dest, char const *src, int n);

#endif
