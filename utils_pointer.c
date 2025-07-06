/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:23:12 by zedurak           #+#    #+#             */
/*   Updated: 2025/07/06 18:43:27 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(size_t p)
{
	int	len;

	len = 0;
	if (p == 0)
	{
		return (ft_putstr("(nil)"));
	}
	len += ft_putstr("0x");
	ft_putptr(p);
	len += ft_ptrlen(p);
	return (len);
}

void	ft_putptr(size_t p)
{
	if (p >= 16)
	{
		ft_putptr(p / 16);
		ft_putptr(p % 16);
	}
	else
	{
		if (p > 9)
			ft_putchar(p - 10 + 'a');
		else
			ft_putchar(p + 48);
	}
}

int	ft_ptrlen(size_t p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	ft_put_hex(unsigned int n, const char format)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_put_hex(n / 16, format);
	if ((n % 16) > 9)
	{
		if (format == 'x')
			len += ft_putchar((n % 16) - 10 + 'a');
		else
			len += ft_putchar((n % 16) - 10 + 'A');
	}
	else
		len += ft_putchar((n % 16) + '0');
	return (len);
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (n == 0)
		return (ft_putchar('0'));
	return (ft_put_hex(n, format));
}
