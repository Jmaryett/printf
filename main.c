#include "ft_printf.h"

int main()
{
	int len;
	int p;
	len = ft_printf(" %p ", -1);
	printf("\nMy length = %d\n", len);
	p = printf(" %p ", -1);
	printf("\nLen that should be = %d", p);
}