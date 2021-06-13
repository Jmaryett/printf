#include "ft_printf.h"

static int	int_no_minus(char *str, t_flags *flagi, int nb, int buf_nb, int str_len)
{
	int	len;
	char	*str_cut;

	len = 0;
	/* if (buf_nb < 0 && flagi->accuracy >= 0 && nb > 2147483648)
		ft_putchar('-'); //len++? */
	if (flagi->accuracy >= 0)
	{
		flagi->accuracy--;
		str_len--;
		len = len + adding_width(flagi, str_len);
	}
	else if (buf_nb < 0)
	{	ft_putchar('-');
		len++;
		str = ft_strtrim(str, "-");
		len = len + my_putstr_for_int(str, flagi, str_len);
		free(str);
		return (len);
	}
	len = len + my_putstr_for_int(str, flagi, str_len);
	//free (str);
	return (len);
}

static int	int_with_minus(char *str, t_flags *flagi, int nb, int buf_nb)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(str);
	/* if (buf_nb < 0 && flagi->accuracy >= 0 && nb > 2147483648)
		ft_putchar('-'); //len++? */
	if (flagi->accuracy >= 0)
	{
		flagi->width -= flagi->accuracy;
		flagi->accuracy--;
		str_len--;
	}
	len = len + my_putstr_for_int(str, flagi, str_len);
	len = len + adding_width(flagi, str_len);
	return (len);
}

static int	handle_flags(t_flags *flagi, int nb)
{
	int	len;
	char *str;
	int str_len;
	int	buf_nb = nb;

	len = 0;
	if (nb == 0 && flagi->accuracy == 0)
		len = len + adding_width(flagi, 0);						  //is it even needed???
	else if (nb < 0 && (flagi->accuracy < 0 || flagi->zero == 1)) //not sure about 2 condition
	{
		nb *= -1;
		flagi->zero = 1;
		flagi->width--;
		len++;
	}
	str = ft_itoa(nb);
	if (flagi->minus == 1)
		{len = len + int_with_minus(str, flagi, nb, buf_nb); free (str); return (len);}
	if (flagi->accuracy >= 0 && flagi->accuracy < str_len) //here width instead of acc???
		flagi->accuracy = str_len;
	else if (flagi->accuracy >= 0 && !(flagi->accuracy < str_len))
	{
		flagi->width -= flagi->accuracy;
		len = len + adding_width(flagi, str_len);
	}
	else if (flagi->accuracy < 0)
	{
		flagi->zero = 1;
		len = len + adding_width(flagi, str_len);
	}
	if (flagi->minus == 0)
		len = len + int_no_minus(str, flagi, nb, buf_nb, str_len);
	free (str);
	return (len);
}

int process_integer(int nb, t_flags *flagi)
{
	int len;

	len = handle_flags(flagi, nb);
	return (len);
}
