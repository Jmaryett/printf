#include "ft_printf.h"

/* static int	handle_minus(char *s, t_flags *flagi)
{
	int	i;
	int len;

	i = -1;
	len = ft_strlen(s);
	if (flagi->accuracy > -1 && flagi->accuracy < len)
		while (++i < flagi->accuracy)
			ft_putchar(s[i]);
	else
		while (++i < len)
			ft_putchar(s[i]);
	while (i < flagi->width)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
} */

static int handle_no_minus(char *str, t_flags *flagi)
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
			ft_putchar(' ');
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

int minus_one(char *str, t_flags *flagi)
{
	int len;

	len = ft_strlen(str);
	if (flagi->accuracy >= 0)
	{
		len = ft_putstr(str, flagi);
		while (len < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
		return (len);
	}
	else
	{
		len = 0 + ft_putstr(str, flagi);
		while (len < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	return (len);
}

int process_string(char *str, t_flags *flagi)
{
	int len;

	len = 0;
	if (!str)
		str = "(null)";
	if (flagi->accuracy >= 0 && flagi->accuracy > (int)ft_strlen(str))
		flagi->accuracy = ft_strlen(str);
	if (flagi->minus == 1)
		len = len + minus_one(str, flagi);
	else
		len = len + handle_no_minus(str, flagi);
	return (len);
}
