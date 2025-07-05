static	int ft_putptr(unsigned long long p)
{
	int	len;

	len = 0;
	if (p == 0)
	{
		len += ft_putchar('0');
		len += ft_putchar('x');
		len += ft_putchar('0');
		return (len);
	}
	len += ft_putstr("0x");
}