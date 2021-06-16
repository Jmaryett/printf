#include "ft_printf.h"

int process_percent(t_flags *flagi)
{
	int len;
	char *str;

	len = 0;
	if (flagi->minus == 1)
		len = len + minus_one("%", flagi);
	else if (flagi->minus == 0)
		len = len + handle_no_minus("%", flagi);
	return (len);
}
