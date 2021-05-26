#include "printf.h"

flags	init_flags(flags flagi)
{
	flagi.accuracy = -1;
	flagi.minus = 0;
	flagi.type = 0;
	flagi.width = 0;
	flagi.zero = 0;
	flagi.star = 0;
	return (flagi);
}

void	parse_flags(char *format, int i, flags flagi, va_list arguments)
{

}

int	parse_format(char *format, va_list arguments)
{
	int	length;
	int	i;
	flags	flagi;

	i = 0;
	length = 0;
	while (1) //если формат больше не парсится, то выходим//
	{
		//1) инициализируем флаги (забиваем в структуру тип, ширину, точность, знак -, знак ссылки на другую переменную(????))
		flagi = init_flags(flagi);
		while(format[i])
		{	
			if(format[i] == '%')
				{
					if (format[++i] == ' ')
						//put space + length ft_putchar(' '); len++;
					parse_flags(format, i, flagi, arguments);
				}
			//put char + length ft_putchar(format[i]); len++;
			i++;
		}
		
	}
	return (length);
}

int ft_printf(const char *format, ...)
{
	int	len;
	va_list	arguments;
	/* va_list	ap2; */

	len = 0;
	va_start(arguments, format);
	len = parse_format(format, arguments);
	/* va_copy(ap2, ap); */
	/* va_arg(ap, void *);*/
	va_end(arguments);
	return (len);
}