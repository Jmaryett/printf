#include "ft_printf.h"

int main()
{
	int len;
	int p;
	len = ft_printf("%0*.*d*0 ", 21, 10, -101);
	write(1, "\n", 1);
	printf("My length = %d\n", len);
	p = printf("%0*.*d*0 ", 21, 10, -101);
	printf("\nLen that should be = %d", p);
}