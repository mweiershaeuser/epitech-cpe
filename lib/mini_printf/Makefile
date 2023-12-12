##
## EPITECH PROJECT, 2023
## Makefile libminiprintf
## File description:
## Makefile for mini_printf
##

NAME	=	"../libminiprintf.a"

SRC		=	miniprintf.c \
			my_put_nbr.c \
			my_putchar.c \
			my_putstr.c \
			my_strlen.c

OBJ = $(SRC:.c=.o)

.PHONY: all compile build clean fclean re

all: $(NAME)

$(NAME): compile build

compile:
	gcc -c $(SRC) -I. -I../../include

build:
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
