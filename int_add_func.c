#include "ft_printf.h"

int my_putstr_for_int(char *s, t_flags *flagi, int str_len)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (flagi->accuracy < 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
			len++;
		}
		return (len);
	}
	else if (flagi->accuracy > str_len)
	{
		while (str_len < flagi->accuracy)
		{
			ft_putchar('0');
			str_len++;
			len++;
		}
	}
	while (s[i] && flagi->accuracy != 0) //or <= ?? or || ??
	{
		write(1, &s[i], 1);
		i++;
		len++;
	}
	return (len);
}

int no_minus_with_zero(char *str, t_flags *flagi)
{
	int len;
	int i;
	int len_output;
	int total_writen;

	i = -1;
	total_writen = 0;
	len = ft_strlen(str);
	if (flagi->accuracy < len && flagi->accuracy > -1)
		len_output = flagi->accuracy;
	else
		len_output = len;
	if (flagi->width > len_output)
		while (++i < flagi->width - len_output)
		{
			ft_putchar('0');
			total_writen++;
		}
	i = -1;
	while (++i < len_output)
	{
		ft_putchar(str[i]);
		total_writen++;
	}
	return (total_writen);
}

int minus_one_with_zero(char *str, t_flags *flagi, int str_len)
{
	if (flagi->accuracy >= 0)
	{
		str_len = my_putstr_for_int(str, flagi, str_len);
		while (str_len < flagi->width)
		{
			ft_putchar('0');
			str_len++;
		}
		return (str_len);
	}
	else
	{
		str_len = 0 + my_putstr(str, flagi);
		while (str_len < flagi->width)
		{
			ft_putchar('0');
			str_len++;
		}
	}
	return (str_len);
}

int adding_width(t_flags *flagi, int str_len)
{
	int len;

	len = 0;
	if (flagi->zero == 1)
	{
		while (str_len < flagi->width)
		{
			ft_putchar('0');
			str_len++;
			len++;
		}
	}
	else
	{
		while (str_len < flagi->width)
		{
			ft_putchar(' ');
			str_len++;
			len++;
		}
	}
	return (len);
}

int minus_one_for_int(char *str, t_flags *flagi)
{
	int len;

	len = ft_strlen(str);
	if (flagi->accuracy >= 0)
	{
		len = my_putstr_for_int(str, flagi, len);
		while (len < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
		return (len);
	}
	else
	{
		len = 0 + my_putstr_for_int(str, flagi, len);
		while (len < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	return (len);
}