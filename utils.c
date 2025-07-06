/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:22:44 by zedurak           #+#    #+#             */
/*   Updated: 2025/07/06 18:30:36 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*s)
	{
		len += ft_putchar(*s);
		s++;
	}
	return (len);
}

int	ft_putnbr(int nbr)
{
	int			len;

	len = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
	len += ft_number_count(nbr, 10);
	return (len);
}

int	ft_number_count(int nbr, int base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / base;
		len++;
	}
	return (len);
}

int	ft_put_unsigned(unsigned int unbr)
{
	int	len;

	len = 0;
	if (unbr >= 10)
		len += ft_put_unsigned(unbr / 10);
	len += ft_putchar((unbr % 10) + '0');
	return (len);
}
