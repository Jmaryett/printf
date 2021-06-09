#include "ft_printf.h"

static char *no_adress(void)
{
	char *s2;

	s2 = malloc(sizeof(char) * 2);
	if (!s2)
		return (NULL);
	s2[0] = '0';
	s2[1] = '\0';
	return (s2);
}

static char *adress_not_zero(unsigned long adress, int count)
{
	char *str;
	unsigned long adr2;

	adr2 = adress;
	while (adress != 0)
	{
		adress = adress / 16;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	str[count] = '\0';
	count--;
	while (adr2 != 0)
	{
		if (adr2 % 16 < 10)
			str[count] = (adr2 % 16) + '0';
		else
			str[count] = (adr2 % 16) + 87;
		adr2 = adr2 / 16;
		count--;
	}
	return (str);
}

static int handle_accuracy(char *str, t_flags *flagi)
{
	int len;

	len = 0;
	if (flagi->minus == 1)
		len = len + minus_one(str, flagi);
	else
		len = len + handle_no_minus(str, flagi);
	free(str);
	return (len);
}

static int no_accuracy(char *str, t_flags *flagi)
{
	int len;

	len = 0;
	if (flagi->minus == 1)
		len = len + minus_one(str, flagi);
	else
		len = len + handle_no_minus(str, flagi);
	free(str);
	return (len);
}

int process_pointer(unsigned long adress, t_flags *flagi)
{
	int final_len;
	int count = 0;
	char *str;

	final_len = 0;
	if (adress == 0)
		str = no_adress();
	else
		str = adress_not_zero(adress, count);
	count = 0;
	str = ft_strjoin("0x", str);
	if (flagi->accuracy >= 0)
		final_len = final_len + handle_accuracy(str, flagi);
	else
		final_len = final_len + no_accuracy(str, flagi);
	return (final_len);
}
