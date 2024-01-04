##
## EPITECH PROJECT, 2023
## Makefile libmy
## File description:
## Makefile libmy
##

NAME	=	"../libmy.a"

SRC		=	miniprintf.c \
			my_put_error.c \
			my_put_nbr.c \
			my_putchar.c \
			my_putstr.c \
			my_strcpy.c \
			my_strlen.c

OBJ = $(SRC:.c=.o)

.PHONY: all compile build clean fclean re

all: $(NAME)

$(NAME): compile build

compile:
	gcc -c $(SRC) -I../../include

build:
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
