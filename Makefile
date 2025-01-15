##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC		?=	gcc

SRC		=		$(addprefix src/, 					\
				main.c								\
				secured.c							\
				)

SRC_TU	=		$(addprefix src/, 					\
				secured.c							\
				)

SRC_TEST	=	$(addprefix tests/,				\
				test_secured.c					\
				)

NAME    	=	libhashtable.a

NAME_DEV	=	secured

NAME_TEST   =	unit_tests

LIB_PATH	=	-L./lib/my -lmy

CFLAGS  	=	-Wall -Wextra

CPPFLAGS	=	-iquote./include/

OBJ			=	$(SRC:.c=.o)

OBJ_LIB		= 	$(SRC_LIB:.c=.o)

UT_OBJ		=	*.gcno *.gcda

all:		$(NAME)

lib_build:
		make -C ./lib/my

$(NAME):	$(OBJ) $(OBJ_LIB)
		$(AR) rc $(NAME) $(OBJ) $(OBJ_LIB)

dev:		$(OBJ)
		make -C ./lib/my
		$(CC) $(OBJ) $(LIB_PATH) -o $(NAME_DEV)

clean:
		$(RM) $(OBJ)

clean_test:
		$(RM) $(UT_OBJ)
		$(RM) $(NAME_TEST)

fclean:		clean clean_test
		make fclean -C ./lib/my
		$(RM) $(NAME) $(NAME_DEV) $(NAME_TEST)

coding-style:	fclean
		coding-style . .
		clear
		cat coding-style-reports.log

re:		fclean all

re_dev: fclean dev

debug: 		CFLAGS += -g3 -ggdb3
debug: 		re_dev

asan: 		CC = clang -fsanitize=address
asan: 		re_dev

unit_tests: 	lib_build
		$(CC) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_TEST) $(SRC_TU) $(LIB_PATH) \
		--coverage -lcriterion

tests_run:	fclean clean_test unit_tests
		./$(NAME_TEST)

.PHONY: all clean fclean coding-style re re_dev debug asan unit-tests tests_run
