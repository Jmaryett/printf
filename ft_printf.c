#include "printf.h"

int ft_printf(const char *str, ...)
{
	int	len;
	va_list	ap;
	va_list	ap2;

	va_start(ap, str);
	va_copy(ap2, ap);
	va_arg(ap, void *);
	va_end(ap);
}