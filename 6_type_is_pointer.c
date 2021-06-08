#include "ft_printf.h"

static char *no_adress(char *s2)
{
	s2 = malloc(sizeof(char) * 2);
	if (!s2)
		return (NULL);
	s2[0] = '0';
	s2[1] = '\0';
	return (s2);
}

int process_pointer(unsigned long adress, t_flags *flagi)
{
	int final_len;
	int count = 0;
	char *str;
	unsigned long adr2 = adress;

	final_len = 0;
	if (adress == 0 && flagi->accuracy == 0)
	{
		final_len = ft_putstr("0x", flagi);
		while (final_len < flagi->width)
		{
			ft_putchar(' ');
			final_len++;
		}
		return (final_len);
	}
	else if (adress == 0)
	{
		str = malloc(sizeof(char));
		str = no_adress(str);
	}
	else
	{
		while (adress != 0)
		{
			adress = adress / 16;
			count++;
		}
		str = malloc(sizeof(char) * (count + 1));
		//str[count] = '\0';
		count--;
		while (adr2 != 0)
		{
			if (adr2 < 10)
				str[count] = (adr2 % 16) + 48;
			else if (adr2 > 10)
				str[count] = (adr2 % 16) + 87;
			adr2 = adr2 / 16;
			count--;
		}
	}
	count = 0;
	final_len = ft_putstr("0x", flagi);
	if (flagi->accuracy >= 0)
	{
		while (final_len < flagi->width)
		{
			ft_putchar(' ');
			final_len++;
		}
		final_len = final_len + ft_putstr(str, flagi);
		return (final_len);
	}
	else
		final_len = final_len + ft_putstr(str, flagi);
	return (final_len);
}