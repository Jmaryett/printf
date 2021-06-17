#include "ft_printf.h"

int main()
{
	int len;
	int p;
	len = ft_printf("%s", NULL, "%d", NULL, "%p", NULL, "%%", NULL, "%c", NULL, "%x", NULL, "%X", NULL, "%u", NULL);
	printf("\nMy length = %d\n", len);
	p = printf("%s", NULL, "%d", NULL, "%p", NULL, "%%", NULL, "%c", NULL, "%x", NULL, "%X", NULL, "%u", NULL);
	printf("\nLen that should be = %d", p);

	//while(1);
}