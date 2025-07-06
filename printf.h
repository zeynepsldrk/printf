/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:28:45 by zedurak           #+#    #+#             */
/*   Updated: 2025/07/06 18:43:42 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_format(va_list a, char s);
int		ft_print_ptr(size_t p);
void	ft_putptr(size_t p);
int		ft_ptrlen(size_t p);
int		ft_put_hex(unsigned int n, const char format);
int		ft_print_hex(unsigned int n, const char format);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int nbr);
int		ft_number_count(int nbr, int base);
int		ft_put_unsigned(unsigned int unbr);

#endif