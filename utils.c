static	int ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static	int ft_putstr(char *s)
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

static	int ft_putnbr(long int nbr)
{
	long int n;
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		n =  nbr * (-1);
	}
	else
		n = nbr;
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
	len += ft_number_count(n, 10);
	return (len);
}

static	int ft_number_count(long int nbr, int base)
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

static	int ft_put_unsigned(unsigned int unbr)
{
	int	len;

	len = 0;
	if (unbr == 0)
		ft_putchar(0);
	len = ft_putnbr(unbr);
	return (len);
}