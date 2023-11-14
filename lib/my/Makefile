##
## EPITECH PROJECT, 2023
## Makefile libmy
## File description:
## Makefile for libmy
##

NAME = "../../libmy.a"

SRC = 	my_is_prime.c \
	my_sort_int_array.c \
	my_str_isnum.c \
	my_strncpy.c \
	my_compute_power_rec.c \
	my_putchar.c \
	my_strcapitalize.c \
	my_str_isprintable.c \
	my_strstr.c \
	my_compute_square_root.c \
	my_put_nbr.c \
	my_strcat.c \
	my_str_isupper.c \
	my_strupcase.c \
	my_find_prime_sup.c \
	my_putstr.c \
	my_strcmp.c \
	my_strlen.c \
	my_swap.c \
	my_getnbr.c \
	my_revstr.c \
	my_strcpy.c \
	my_strlowcase.c \
	my_showmem.c \
	my_str_isalpha.c \
	my_strncat.c \
	my_isneg.c \
	my_showstr.c \
	my_str_islower.c \
	my_strncmp.c

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
