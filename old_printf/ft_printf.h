#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	/* int	c;
	int	s;
	int	p;
	int	d;
	int	i;
	int	u;
	int	x;
	int	X;
	int	percent; */
	char	type;
	int	width;
	int	accuracy;
	int	minus;
	int zero;
	int	star;
	//int	dot;
}				t_flags;

int ft_printf(const char *format, ...);

int	check_digit(char *format, int i);
int	check_type(char *format, int i);
int	check_flag(char *format, int i);
int	we_met_zero(char *format, int i, t_flags *flagi);
int check_next_char_after_zero(char *format, int i);
void	analyze_minus(t_flags *flagi);
int analyze_accuracy(char *format, int i, t_flags *flagi, va_list arg);
void	analyze_width(va_list arg, t_flags *flagi);
void	analyze_width_2(char c, t_flags *flagi);
int	process_types(char type, t_flags *flagi, va_list arg/* , int len */);
int	process_char(char c, t_flags *flagi/* , int len */);
size_t	ft_strlen(const char *str);
int	process_string(char *str, t_flags *flagi);
void	ft_putchar(char c);
int	ft_putstr(char *s, t_flags *flagi, int len);

#endif