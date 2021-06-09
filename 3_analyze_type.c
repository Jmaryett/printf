#include "ft_printf.h"

int process_types(char type, t_flags *flagi, va_list arg /* , int len */)
{
	int len;

	len = 0;
	if (type == 'c')
	{
		char c = va_arg(arg, int);
		len = process_char(c, flagi);
	}
	if (type == 's')
		len = process_string(va_arg(arg, char *), flagi);
	if (type == 'p')
		len = process_pointer(va_arg(arg, unsigned long), flagi);
	if (type == 'd' || type == 'i')
		len = process_integer(va_arg(arg, int), flagi);
	return (len);
}