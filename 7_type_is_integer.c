#include "ft_printf.h"

static int handle_width_with_minus(t_flags *flagi, char *str)
{
	int len = 0;

	while (flagi->width > 0)
	{
		ft_putchar(' ');
		flagi->width--;
		len++;
	}
	return (len);
}

static int putstr_for_minus(t_flags *flagi, char *str, int str_len, int nb)
{
	int i = 0;
	int len = 0;

	if (nb < 0)
	{
		ft_putchar('-');
		len++;
	}
	if (flagi->accuracy > str_len)
	{
		while (str_len < flagi->accuracy)
		{
			ft_putchar('0');
			str_len++;
			len++;
		}
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	flagi->width -= len;
	len = len + handle_width_with_minus(flagi, str);
	return (len);
}

static int handle_minus(char *str, t_flags *flagi, int nb)
{
	int len = 0;
	int str_len = ft_strlen(str);
	flagi->zero = 0;
	len = len + putstr_for_minus(flagi, str, str_len, nb);
	return (len);
}

static int putstr_no_minus(t_flags *flagi, char *str, int str_len, int nb)
{
	int len = 0;
	int i = 0;
	if (flagi->accuracy > str_len)
	{
		while (str_len < flagi->accuracy)
		{
			ft_putchar('0');
			str_len++;
			len++;
		}
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	return (len);
}

static int no_minus_width_with_acc(t_flags *flagi, char *str, int nb)
{
	int len = 0;
	int str_len = ft_strlen(str);
	if (flagi->accuracy < str_len)
		flagi->accuracy = str_len;
	if (nb < 0)
		flagi->width -= (flagi->accuracy + 1);
	else if (nb >= 0)
		flagi->width -= flagi->accuracy;
	while (flagi->width > 0)
	{
		if (flagi->zero == 1)
		{
			ft_putchar('0');
			flagi->width--;
			len++;
		}
		else if (flagi->zero == 0)
		{
			ft_putchar(' ');
			flagi->width--;
			len++;
		}
	}
	len = len + putstr_for_minus(flagi, str, str_len, nb);
	return (len);
}

static int handle_no_minus_int(t_flags *flagi, char *str, int nb)
{
	int len = 0;
	int str_len = ft_strlen(str);

	if (flagi->accuracy >= 0)
	{
		flagi->zero = 0;
		len = len + no_minus_width_with_acc(flagi, str, nb); //put width up to acc and then str
	}
	else if (flagi->accuracy < 0)
	{
		//put width (with zero or not) up to str_len and then putstr
		if (nb < 0)
		{
			ft_putchar('-');
			flagi->width--;
			len++;
		}
		while (str_len < flagi->width)
		{
			if (flagi->zero == 1)
			{
				ft_putchar('0');
				str_len++;
				len++;
			}
			else if (flagi->zero == 0)
			{
				ft_putchar(' ');
				str_len++;
				len++;
			}
		}
		len = len + putstr_no_minus(flagi, str, str_len, nb);
	}
	return (len);
}

int process_integer(int nb, t_flags *flagi)
{
	int len;
	char *str;
	int nb2 = nb;

	len = 0;
	if (nb == 0 && flagi->accuracy == 0)
	{
		str = ft_strdup("");
		len = handle_width_with_minus(flagi, str);
		len = len + putstr_for_minus(flagi, str, ft_strlen(str), nb2);
		free(str);
		return (len);
	}
	if (nb < 0 && nb != -2147483648)
		nb *= -1;
	str = ft_itoa(nb);
	if (flagi->minus == 1)
		len = len + handle_minus(str, flagi, nb2);
	else if (flagi->minus == 0)
		len = len + handle_no_minus_int(flagi, str, nb2);
	free(str);
	return (len);
}