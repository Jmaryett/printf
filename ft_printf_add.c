#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char *s, t_flags *flagi)
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
	while (s[i] && i < flagi->accuracy) //or <= ?? or || ??
	{
		write(1, &s[i], 1);
		i++;
		len++;
	}
	return (len);
}

/* int my_putstr_for_int(char *s, t_flags *flagi, int str_len)
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
	while (s[i] && i < flagi->accuracy) //or <= ?? or || ??
	{
		write(1, &s[i], 1);
		i++;
		len++;
	}
	return (len);
}
 */