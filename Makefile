##
## EPITECH PROJECT, 2023
## organized
## File description:
## Makefile
##

MAIN		=	main.c

SRC			=	organized.c

OBJ			=	$(SRC:.c=.o)

NAME		=	organized

LIB			=	lib/libmy.a

LIBSHELL	=	shell

TESTS		=	unit_tests

.PHONY: all \
	clean_lib clean_emacs clean_tests clean \
	fclean_lib fclean \
	re \
	tests_run tests_run_cov

all: $(NAME)

$(LIB):
	cd lib/my && make re

$(NAME): $(LIB)
	gcc -o $(NAME) -Wall -Wextra \
	$(MAIN) $(SRC) \
	-I include \
	-I shell \
	-L lib -lmy \
	-L shell -l$(LIBSHELL)

clean_lib:
	cd lib/my && make clean

clean_emacs:
	find . \( -name "*~" -or -name "#*#" \) -delete

clean_tests:
	rm -f $(TESTS)
	rm -rf coverage

clean: clean_emacs clean_lib
	rm -f $(OBJ)

fclean_lib:
	cd lib/my && make fclean

fclean: clean clean_tests fclean_lib
	rm -f $(NAME)

re: fclean all

$(TESTS): $(LIB)
	mkdir -p coverage
	cd coverage && \
	gcc -o $(TESTS) -Wall -Wextra \
	$(addprefix ../,$(SRC)) ../tests/*.c \
	-I ../include \
	-L ../lib -lmy \
	--coverage -lcriterion

tests_run: $(TESTS)
	cd coverage && ./$(TESTS)

tests_run_cov: $(TESTS)
	cd coverage && ./$(TESTS)
	gcovr --exclude tests
	gcovr --exclude tests --branches
