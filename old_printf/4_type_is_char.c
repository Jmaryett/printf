#include "ft_printf.h"

int	process_char(char c, t_flags *flagi/* , int len */)
{
	int len;
	
	len = 0;
	if(flagi->minus == 1)
	{
		ft_putchar(c);
		if (flagi->width > 0)
		{
			flagi->width--;
			while (flagi->width > 0)
			{
				ft_putchar(' ');
				flagi->width--;
				len++;
			}
		}
		return(len + 1);
	}
	if(flagi->width > 0)
	{
		flagi->width--;
		while (flagi->width > 0)
		{
			ft_putchar(' ');
			flagi->width--;
			len++;
		}
	}
	ft_putchar(c);
	return(len + 1);
}