#include "ft_printf.h"

int	minus_one(char *str, t_flags *flagi)
{
	int len;

	len = 0;
	if (flagi->accuracy >= 0)
		{
			len = len + ft_putstr(str, flagi);
			while(flagi->width > 0)
			{
				ft_putchar(' ');
				flagi->width--;
				len++;
			}
		}
	else
		{
			len = len + ft_putstr(str, flagi);
			while(flagi->width > (int)ft_strlen(str))
			{
				ft_putchar(' ');
				flagi->width--;
				len++;
			}
		}
	return (len);
}

/* int	check_acc_str(t_flags *flagi, int len, char *str)
{
	if (flagi->accuracy > 0 && flagi->width > 0)
	{
		while (flagi->width > flagi->accuracy)
		{
			ft_putchar(' ');
			flagi->width--;
			len++;	
		}
	}
	 if (flagi->accuracy < 0 || !flagi->accuracy)
	{
		while (flagi->width > 0 (int)ft_strlen(str))
		{
			ft_putchar(' ');
			flagi->width--;
			len++;
		}
	}
	return (len);
} */

int	process_string(char *str, t_flags *flagi)
{
	int	len;

	len = 0;
	if (!str)
		write(1, NULL, 1);
	if (flagi->accuracy >= 0 && flagi->accuracy > (int)ft_strlen(str))
		flagi->accuracy = ft_strlen(str);
	if (flagi->minus == 1)
	{
		len = len + minus_one(str, flagi);
		return (len);
	}
	//len = check_acc_str(flagi, len, str);
	if (flagi->minus == 0)
	{
		if (flagi->accuracy < 0 && flagi->width > 0)
		{
			while(flagi->width-- > (int)ft_strlen(str))
			{
				ft_putchar(' ');
				len++;
			}
			len = len + ft_putstr(str, flagi);
			return (len);
		}
		else if (flagi->accuracy >= 0) /* && flagi->accuracy > (int)ft_strlen(str)) */
		{
			while(flagi->width > (int)ft_strlen(str))
			{
				ft_putchar(' ');
				flagi->width--;
				len++;
			}
			len = len + ft_putstr(str, flagi);
			return (len);
		}
	}
	len = len + ft_putstr(str, flagi);
	return (len);
}
