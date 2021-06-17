#include "ft_printf.h"

int main()
{
	int len;
	int p;
	len = ft_printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42);
	printf("\nMy length = %d\n", len);
	p = printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42);
	printf("\nLen that should be = %d", p);

	//while(1);
}