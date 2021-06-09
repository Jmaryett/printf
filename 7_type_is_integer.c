#include "ft_printf.h"

int process_integer(int nb, t_flags *flagi)
{
	int buf_nb; //???
	char *str;
	int len;

	len = 0;
	buf_nb = nb; //????
	if (nb == 0 || flagi->accuracy == 0)
	{
		while (len < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
		return (len);
	}															  //is it even needed???
	else if (nb < 0 && (flagi->accuracy < 0 || flagi->zero == 1)) //not sure about 2 condition
	{
		if (flagi->zero == 1 && flagi->accuracy < 0 && nb > -2147483648)
			len = my_putstr("-", flagi); //needed????
		else if (nb = -2147483648)
			len--; //maybe that is not needed also
		nb = nb * (-1);
		flagi->zero = 1;
		flagi->width--;
		len++;
	}
	str = ft_itoa(nb);
	if (flagi->minus == 1)
	{
		if (buf_nb < 0 && flagi->accuracy >= 0 && nb > 2147483648)
			ft_putchar('-');
		if (flagi->accuracy >= 0 && flagi->zero == 1)
			len = len + minus_one_with_zero(str, flagi);
		else if (flagi->accuracy >= 0 && flagi->zero == 0)
			len = len + minus_one(str, flagi);
		else
			len = len + my_putstr(str, flagi);
	}
	if (flagi->width >= 0 && flagi->accuracy < (int)ft_strlen(str)) //here width instead of acc???
		flagi->accuracy = (int)ft_strlen(str);
	if (flagi->accuracy >= 0)
	{
		flagi->width = flagi->width - flagi->accuracy;
		while (flagi->width)
		{
			ft_putchar(' ');
			flagi->width--;
			len++;
		}
	}
	else if (flagi->accuracy < 0)
	{
		if (flagi->zero == 1)
		{
			while (flagi->width != (int)ft_strlen(str))
			{
				ft_putchar('0');
				flagi->width--;
				len++;
			}
		}
		else
		{
			while (flagi->width != (int)ft_strlen(str))
			{
				ft_putchar(' ');
				flagi->width--;
				len++;
			}
		}
	}
	if (flagi->minus == 0)
	{
		if (buf_nb < 0 && flagi->accuracy >= 0 && nb > 2147483648)
			ft_putchar('-');
		else
		{
			if (flagi->accuracy >= 0)
		}
	}
}