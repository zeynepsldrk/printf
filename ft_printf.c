/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:01:35 by zedurak           #+#    #+#             */
/*   Updated: 2025/07/08 17:59:13 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_error(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				return (-1);
			if (!(str[i] == 'c' || str[i] == 'i' || str[i] == 'd'
					|| str[i] == 'p' || str[i] == 's' || str[i] == 'u'
					|| str[i] == 'x' || str[i] == 'X' || str[i] == '%'))
			{
				return (-1);
			}
			i++;
		}
		i++;
	}
	return (0);
}

int	ft_format(va_list a, char s)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_putchar(va_arg(a, int));
	else if (s == 's')
		len += ft_putstr(va_arg(a, char *));
	else if (s == 'p')
		len += ft_print_ptr(va_arg(a, size_t));
	else if (s == 'd' || s == 'i')
		len += ft_putnbr(va_arg(a, int));
	else if (s == 'u')
		len += ft_put_unsigned(va_arg(a, unsigned int));
	else if (s == 'x' || s == 'X')
		len += ft_print_hex(va_arg(a, int), s);
	else if (s == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(list, str);
	if (is_error(str) == -1)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_format(list, str[i + 1]);
			i += 2;
		}
		else
		{
			len += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(list);
	return (len);
}