SRC		=	lst_utils.c  parse_arg.c  parse_arg_utils.c  push_swap_main.c utils.c swap.c push.c \
			rotate.c rev_rotate.c sort.c big_sort.c greedy_algo.c

CFLAGS	=	-Wall -Werror -Wextra -I.

OBJ		=	${SRC:.c=.o}

NAME	=	push_swap

all:	${NAME}

${NAME}:	${OBJ}
			cc -Wall -Wextra -Werror -ggdb ${OBJ} -o ${NAME}
clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean ${NAME}

.PHONY	=	all clean fclean re
