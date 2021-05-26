#ifndef PRINTF_H

# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdio.h>
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
	int	type;
	int	width;
	int	accuracy;
	int	minus;
	int zero;
	int	star;
}				flags;

void	ft_putchar(char c);

#endif