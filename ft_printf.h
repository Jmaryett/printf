#ifndef FT_PRINTF_H

#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_list
{
	char type;
	int width;
	int accuracy;
	int minus;
	int zero;
	int star;
} t_flags;

int ft_printf(const char *format, ...);

int check_digit(char *format, int i);
int check_type(char *format, int i);
int check_flag(char *format, int i);
int we_met_zero(char *format, int i, t_flags *flagi);
int check_next_char_after_zero(char *format, int i);
void analyze_minus(t_flags *flagi);
int analyze_accuracy(char *format, int i, t_flags *flagi, va_list arg);
void analyze_width(va_list arg, t_flags *flagi);
void analyze_width_2(char c, t_flags *flagi);
int process_types(char type, t_flags *flagi, va_list arg /* , int len */);
int char_with_width_only(t_flags *flagi, int len);
int process_char(char c, t_flags *flagi /* , int len */);
int process_string(char *str, t_flags *flagi);
int process_pointer(unsigned long adress, t_flags *flagi);
int process_integer(int nb, t_flags *flagi);
int adding_width(t_flags *flagi, int str_len);
int my_putstr_for_int(char *s, t_flags *flagi, int str_len);
int minus_one_for_int(char *str, t_flags *flagi);
//char *ft_strjoin(char const *s1, char const *s2);
//size_t ft_strlen(const char *str);
int minus_one(char *str, t_flags *flagi);
int minus_one_with_zero(char *str, t_flags *flagi, int str_len);
int no_minus_with_zero(char *str, t_flags *flagi);
int handle_no_minus(char *str, t_flags *flagi);
void ft_putchar(char c);
int my_putstr(char *s, t_flags *flagi);

#endif