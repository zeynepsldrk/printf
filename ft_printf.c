/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:01:35 by zedurak           #+#    #+#             */
/*   Updated: 2025/07/02 21:19:44 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static	int ft_format(va_list a, char *s)
{
	int	len;

	len = 0;
	
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int	i;
	int	len;

	len = 0;
	i = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			len += ft_format(list, str[i + 1]);
		else
		{
			len += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(list);
	return (len);
}

