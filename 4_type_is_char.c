#include "ft_printf.h"

int	char_with_width_only(t_flags *flagi, int len)
{
	flagi->width--;
	while (flagi->width-- > 0) //maybe shoud decrese width in cycle 
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

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
			while (flagi->width-- > 0) ////maybe shoud decrese width in cycle 
			{
				ft_putchar(' ');
				len++;
			}
		}
		return(len + 1);
	}
	if(flagi->width > 0)
		len = char_with_width_only(flagi, len);
	ft_putchar(c);
	return(len + 1);
}