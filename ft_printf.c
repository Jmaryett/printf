#include "ft_printf.h"

static void	init_t_flags(t_flags *flagi)
{
	flagi->accuracy = -1;
	flagi->minus = 0;
	flagi->type = 'o';
	flagi->width = 0;
	flagi->zero = 0;
	flagi->star = 0;
}

static int	parse_t_flags(char *format, int i, t_flags *flagi, va_list arguments)
{
	while (format[i])
	{
		if (!check_digit(format, i) && !check_type(format, i) 
		&& !check_flag(format, i))
			return (i);
		if (format[i] == '0') //?? if or while
			i = we_met_zero(format, i, flagi);
		if (format[i] == '.')
			i = analyze_accuracy(format, i, flagi, arguments);
		if (format[i] == '-')
			analyze_minus(flagi);
		if (format[i] == '*')
			analyze_width(arguments, flagi);
		if (format[i] >= '0' && format[i] <= '9')
			analyze_width_2(format[i], flagi);
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
		|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
		{
			flagi->type = format[i];
			return (i);
		}
		i++;
	}
	return (i);
}

static int thx_norms(char *format, va_list arguments, int i, int length, t_flags *flagi)
{
	while (format[i])
	{
		init_t_flags(flagi);
		if (format[i] == '%')
			{
				while (format[++i] == ' ')
					{
						ft_putchar(' '); 
						length++;
					}
				i = parse_t_flags(format, i, flagi, arguments);
				if (flagi->type != 'o')
						length = length + process_types(format[i], flagi, arguments/* , length */);
			}
		else if (format[i] != '%')
		{	
			ft_putchar(format[i]);
			length++;
		}
		i++;
	}
	return (length);
}

static int	parse_input(char *format, va_list arguments)
{
	int		length;
	int		i;
	t_flags	flagi;

	i = 0;
	length = 0;
	length = thx_norms(format, arguments, i, length, &flagi);
	return (length);
}

int ft_printf(const char *format, ...)
{
	int		len;
	va_list	arguments;

	len = 0;
	va_start(arguments, format);
	len = parse_input((char*)format, arguments);
	va_end(arguments);
	return (len);
}

int main()
{
	int	len;
	len = ft_printf(" %*.s %.1s ", 10, "123", "4567");
	write(1, "\n", 1);
	printf("length = %d", len);
}