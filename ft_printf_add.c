#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}
/* size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
} */

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

int minus_one_with_zero(char *str, t_flags *flagi)
{
	int len;

	len = ft_strlen(str);
	if (flagi->accuracy >= 0)
	{
		len = ft_putstr(str, flagi);
		while (len < flagi->width)
		{
			ft_putchar('0');
			len++;
		}
		return (len);
	}
	else
	{
		len = 0 + ft_putstr(str, flagi);
		while (len < flagi->width)
		{
			ft_putchar('0');
			len++;
		}
	}
	return (len);
}

/* char *ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
} */

/* int put_pointer(char *str, t_flags *flagi)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (flagi->minus == 1)
	{
	}
	else
	{
	}
} */