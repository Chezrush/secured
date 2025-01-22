##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC				?=	gcc

HASH_PATH		=	hash/

MANAGER_PATH	=	manager/

DUMP_PATH		=	dump/

LIB_LINKED_LIST =	lib_linked_list/

SRC				=	$(addprefix src/, 					\
					main.c								\
					secured.c							\
					$(HASH_PATH)hash.c					\
					$(HASH_PATH)init_sha_hash.c			\
					$(HASH_PATH)update_sha_hash.c		\
					$(HASH_PATH)transform_sha_hash.c	\
					$(HASH_PATH)get_id_table.c			\
					$(HASH_PATH)final_sha_hash.c		\
					$(MANAGER_PATH)delete.c				\
					$(MANAGER_PATH)insert.c				\
					$(MANAGER_PATH)search.c 			\
					$(MANAGER_PATH)delete_hashtable.c 	\
					$(DUMP_PATH)dump.c					\
					$(LIB_LINKED_LIST)linked_lists.c	\
					create_hashtable.c 					\
					)

SRC_TU			=	$(addprefix src/, 					\
					$(HASH_PATH)hash.c					\
					$(HASH_PATH)init_sha_hash.c			\
					$(HASH_PATH)update_sha_hash.c		\
					$(HASH_PATH)transform_sha_hash.c	\
					$(HASH_PATH)get_id_table.c			\
					$(HASH_PATH)final_sha_hash.c		\
					$(MANAGER_PATH)delete.c				\
					$(MANAGER_PATH)insert.c				\
					$(MANAGER_PATH)search.c 			\
					$(DUMP_PATH)dump.c					\
					$(LIB_LINKED_LIST)linked_lists.c	\
					create_hashtable.c 					\
					)

SRC_TEST		=	$(addprefix tests/,					\
					test_secured.c						\
					)

NAME    		=	libhashtable.a

NAME_DEV		=	secured

NAME_TEST   	=	unit_tests

LIB_PATH		=	-L./lib/my -lmy

CFLAGS  		=	-Wall -Wextra

CPPFLAGS		=	-iquote./include/

OBJ				=	$(SRC:.c=.o)

OBJ_LIB			= 	$(SRC_LIB:.c=.o)

UT_OBJ			=	*.gcno *.gcda

all:		$(NAME)

lib_build:
		make -C ./lib/my

$(NAME):	$(OBJ) $(OBJ_LIB)
		$(AR) rc $(NAME) $(OBJ) $(OBJ_LIB)

dev:		$(OBJ)
		make -C ./lib/my
		$(CC) $(OBJ) $(LIB_PATH) -o $(NAME_DEV) $(LDFLAGS)

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

redev: fclean dev

debug: 		CFLAGS += -g3 -ggdb3
debug: 		redev

asan: 		CFLAGS += -fsanitize=address -g3 -ggdb3
asan:		LDFLAGS += -fsanitize=address
asan: 		redev

unit_tests: 	lib_build
		$(CC) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_TEST) $(SRC_TU) $(LIB_PATH) \
		--coverage -lcriterion

tests_run:	fclean clean_test unit_tests
		./$(NAME_TEST)

.PHONY: all clean fclean coding-style re re_dev debug asan unit-tests tests_run
