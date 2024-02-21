##
## EPITECH PROJECT, 2023
## secured
## File description:
## Makefile
##

NAME		=	libhashtable.a

SRC			=	src/hash.c \
				src/create_table.c \
				src/delete_table.c \
				src/dump.c \
				src/insert.c \
				src/delete.c \
				src/search.c \
				src/find_entry.c

OBJ			=	$(SRC:.c=.o)

LIB			=	lib/my/miniprintf.c \
				lib/my/my_put_error.c \
				lib/my/my_put_nbr.c \
				lib/my/my_putchar.c \
				lib/my/my_putstr.c \
				lib/my/my_strcpy.c \
				lib/my/my_strlen.c

LIBOBJ		=	$(LIB:.c=.o)

TESTS		=	unit_tests

.PHONY: all \
	clean_emacs clean_tests clean \
	fclean \
	re \
	tests_run tests_run_cov

all: $(NAME)

$(NAME): $(OBJ) $(LIBOBJ)
	ar rc $(NAME) $(OBJ) $(LIBOBJ)

clean_emacs:
	find . \( -name "*~" -or -name "#*#" \) -delete

clean_tests:
	rm -f $(TESTS)
	rm -rf coverage

clean: clean_emacs
	rm -f $(OBJ) $(LIBOBJ)

fclean: clean clean_tests
	rm -f $(NAME)

re: fclean all

$(TESTS):
	mkdir -p coverage
	cd coverage && \
	gcc -o $(TESTS) -Wall -Wextra \
	$(addprefix ../,$(SRC)) $(addprefix ../,$(LIB)) \
	../tests/*.c \
	-I ../include \
	--coverage -lcriterion

tests_run: $(TESTS)
	cd coverage && ./$(TESTS)

tests_run_cov: $(TESTS)
	cd coverage && ./$(TESTS)
	gcovr --exclude tests --exclude lib
	gcovr --exclude tests --exclude lib --branches
