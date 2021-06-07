#include <stdio.h>

int main()
{
	int p;
	/* printf("%02d\n your mama gay", 1);
	printf("%0-60d\n", 78);
	printf("%%c\n");
	printf("%10.3f", 12.234657); */
	p = printf(" %*.3s %.3s ", 10, "123", "4567");
	printf ("\nlenght = %d", p);
	return (0);
}