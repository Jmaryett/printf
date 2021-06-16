#include "ft_printf.h"

int main()
{
	int len;
	int p;
	len = ft_printf(" %-3.s ", NULL);
	printf("\nMy length = %d\n", len);
	p = printf(" %-3.s ", NULL);
	printf("\nLen that should be = %d", p);

	//while(1);
}