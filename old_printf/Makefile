NAME = libftprintf.a
	
HEADER	= ft_printf.h

SRCS	= ft_printf.c \
		ft_printf_add.c \
		1_checking_symbols_for_flags.c \
		2_analyzing_flags.c \
		3_analyze_type.c \
		4_type_is_char.c \
		5_type_is_str.c \

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

AR	= ar rc

CFLAGS 	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}
	
${NAME}:	${OBJS} ${HEADER}
			${AR} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} ${OBJS2}

fclean:	clean
		${RM} ${NAME}
		
re:		fclean all

#bonus: ${OBJS2} ${HEADER}
#		${AR} ${NAME} $^

.PHONY: re clean fclean all 