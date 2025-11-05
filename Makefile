##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

UTILS		= src/utils/

TYPE		= src/type/

FLAG		= src/flag/

PARSING		= src/parsing/

CFLAGS  	= -Wall -Wextra

CPPFLAGS 	= -iquote ./include/

SRC	=	$(UTILS)my_putchar.c				\
		$(UTILS)my_put_nbr.c				\
		$(UTILS)my_strncat.c 				\
		$(UTILS)my_strdup.c 				\
		$(UTILS)my_putstr.c					\
		$(UTILS)my_strlen.c					\
		$(UTILS)my_putfloat.c				\
		$(UTILS)my_revstr.c					\
		$(UTILS)my_putnbr_base.c			\
		$(UTILS)my_strncpy.c 				\
		$(TYPE)is_adress.c					\
		$(TYPE)is_n.c						\
		$(TYPE)is_int.c						\
		$(TYPE)is_char.c					\
		$(TYPE)is_string.c					\
		$(TYPE)is_pourcent.c				\
		$(TYPE)is_uint.c 					\
		$(TYPE)is_float.c 					\
		$(TYPE)is_floatupper.c 				\
		$(TYPE)is_octal.c 					\
		$(TYPE)is_uhexaintupper.c			\
		$(TYPE)is_uhexaint.c				\
		$(TYPE)is_scien.c 					\
		$(TYPE)is_scienupper.c 				\
		$(TYPE)is_short.c 					\
		$(TYPE)is_shortupper.c 				\
		$(FLAG)handle_flags.c 				\
		$(FLAG)handle_precision.c 			\
		$(FLAG)handle_flag_char.c 			\
		$(FLAG)handle_flag_float.c 			\
		$(PARSING)parse_flag.c 				\
		$(PARSING)parse_width.c 			\
		$(PARSING)parse_precision.c 		\
		$(PARSING)parse_length.c 			\
		$(PARSING)parse_specifier.c 		\
		$(PARSING)parse_format.c 			\
		src/handle_struct.c 				\
		src/handle_format.c 				\
		src/my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

TEST_FLAG =	-lcriterion --coverage

TEST_SRC = 	tests/my_printf_test.c

TEST_OBJ =	$(TEST_SRC:.c=.o)

ALL_TEST_OBJ = 	$(OBJ) $(TEST_OBJ)

TEST_NAME = 	myprintf_test

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all

unit_tests: $(OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_NAME) $(SRC) $(TEST_SRC) $(CFLAGS) $(CPPFLAGS) $(TEST_FLAG)

tests_run: unit_tests
	./$(TEST_NAME)
	gcovr --exclude tests/
	gcovr --exclude tests/ --txt-metric branch

test_clean:
	rm -f $(TEST_NAME)
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(OBJ)
	rm -f $(TEST_OBJ)

.PHONY: all clean fclean re
