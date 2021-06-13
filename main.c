#include "ft_printf.h"

int main()
{
	int len;
	int p;
	len = ft_printf(" %-3.2d %10.42d ", 1, -1);
	printf("\nMy length = %d\n", len);
	p = printf(" %-3.2d %10.42d ", 1, -1);
	printf("\nLen that should be = %d", p);
}