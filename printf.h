#ifndef PRİNTF_H
#define PRİNTF_H

#include <stdarg.h>
#include <unistd.h>


int	ft_printf(const char *str, ...);
static	int ft_format(va_list a, char *s);

#endif