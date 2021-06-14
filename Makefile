LIBFT = -L libft -lft

LIBFT_C = ./libft/*.c

LIBFT_A = ./libft/libft.a

NAME = libftprintf.a
	
HEADER	= ft_printf.h \

SRCS	= ft_printf.c \
		ft_printf_add.c \
		int_add_func.c \
		1_checking_symbols_for_flags.c \
		2_analyzing_flags.c \
		3_analyze_type.c \
		4_type_is_char.c \
		5_type_is_str.c \
		6_type_is_pointer.c \
		7_type_is_integer.c 

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

AR	= ar rc

CFLAGS 	= -Wall -Wextra -Werror

LIBA = libft.a

.c.o:
	${CC} -c $< -o ${<:.c=.o}

all: ${NAME}

compile_libft: ${LIBFT_A}

${LIBFT_A}:
			cd ./libft; \
			make; \
			cp $(LIBA) ../; \
			make clean; \
			cd ..;
			mv ${LIBA} ${NAME}
	
${NAME}:	${LIBFT_A} ${OBJS} ${HEADER}
			${AR} ${NAME} ${OBJS}


clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} ${LIBFT_A}
		
test:	${LIBFT_A}
		${CC} -o -g main.c ${SRCS} ${LIBFT_A}
		${RM} ${OBJS} ${LIBFT_A} ${NAME}

re:		fclean all

#bonus: ${OBJS2} ${HEADER}
#		${AR} ${NAME} $^

.PHONY: re clean fclean all 