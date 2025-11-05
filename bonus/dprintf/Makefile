##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CFLAGS  	= -Wall -Wextra

CPPFLAGS 	= -iquote ./include

SRC	=	src/lib/my_putchar.c		\
		src/lib/my_put_nbr.c		\
                src/lib/my_putfloat.c            \
		src/lib/my_putstr.c		\
		src/type/is_int.c		\
		src/type/is_str.c		\
		src/type/is_flt.c		\
		src/type/is_chr.c		\
		src/type/is_pct.c		\
		src/mini_dprintf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
