#include "ft_printf.h"

int process_integer(int nb, t_flags *flagi)
{
	//int buf_nb; //???
	char *str;
	int len;
	int str_len;

	len = 0;
	//buf_nb = nb; //????
	if (nb == 0 && flagi->accuracy == 0)
		len = len + adding_width(flagi, 0);						  //is it even needed???
	else if (nb < 0 && (flagi->accuracy < 0 || flagi->zero == 1)) //not sure about 2 condition
	{
		nb = nb * (-1);
		flagi->zero = 1;
		flagi->width--;
		len++;
	}
	if (nb < 0 && flagi->accuracy >= 0)
	{
		ft_putchar('-');
		nb *= -1;
		len++;
	}
	str = ft_itoa(nb);
	str_len = ft_strlen(str);
	if (flagi->minus == 1)
	{
		if (flagi->accuracy >= 0)
		{
			if (flagi->zero == 1)
				len = len + minus_one_with_zero(str, flagi, str_len);
			else if (flagi->zero == 0)
				len = len + minus_one_for_int(str, flagi);
			free(str);
			return (len);
		}
		else
		{
			flagi->accuracy--;
			str_len--;
			flagi->zero = 1;
			len = len + adding_width(flagi, str_len);
		}
	}
	else
		len = len + my_putstr_for_int(str, flagi, str_len);
	if (flagi->accuracy >= 0 && flagi->accuracy < str_len) //here width instead of acc???
		flagi->accuracy = str_len;
	if (flagi->accuracy >= 0)
	{
		flagi->width = flagi->width - flagi->accuracy;
		len = len + adding_width(flagi, str_len);
	}
	else if (flagi->accuracy < 0)
	{
		flagi->zero = 1;
		len = len + adding_width(flagi, str_len);
	}
	if (flagi->minus == 0)
	{
		if (flagi->accuracy >= 0)
		{
			flagi->accuracy--;
			str_len--;
			flagi->zero = 1;
			len = len + adding_width(flagi, str_len);
		}
	}
	else
		len = len + my_putstr_for_int(str, flagi, str_len);
	free(str);
	return (len);
}

/* int process_integer(int nb, t_flags *flagi)
{
	char *str;
	int str_len;
	int len;
	int buf_nb = nb;

	len = 0;
	if (flagi->accuracy == 0 && nb == 0)
		len = len + adding_width(flagi, 0);
	else if (nb < 0 && (flagi->accuracy < 0 || flagi->zero == 1))
	{
		if (flagi->zero == 1 && flagi->accuracy < 0 && nb > -2147483647)
			len = len + my_putstr_for_int("-", flagi, 1);
		else if (nb == -2147483648)
			len--;
		nb *= (-1);
		flagi->zero = 1;
		flagi->width--;
		len++;
	}
	str = ft_itoa(nb);
	if (flagi->minus == 1)
	{
		if (nb < 0 && flagi->accuracy >= 0 && buf_nb > 2147483648)
			ft_putchar('-');
		if (flagi->accuracy >= 0)
		{
			flagi->accuracy--;
			str_len--;
			flagi->zero = 1;
			len = len + adding_width(flagi, str_len);
		}
		len = len + my_putstr_for_int(str, flagi, str_len);
	}
	else if (flagi->accuracy >= 0 && flagi->accuracy < str_len)
		flagi->accuracy = str_len;
	else if (flagi->accuracy >= 0)
	{
		flagi->width -= flagi->accuracy;
		len = len + adding_width(flagi, str_len);
	}
	else if (flagi->accuracy < 0)
	{
		flagi->zero = 1;
		len = len + adding_width(flagi, str_len);
	}
	if (flagi->minus == 0)
	{
		if (buf_nb < 0 && flagi->accuracy >= 0 && nb > 2147483648)
			ft_putchar('-');
		else if (flagi->accuracy >= 0)
		{
			flagi->accuracy--;
			str_len--;
			flagi->zero = 1;
			len = len + adding_width(flagi, str_len);
		}
		len = len + my_putstr_for_int(str, flagi, str_len);
	}
	free(str);
	return (len); */