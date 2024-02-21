/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

int print_digit(int nb)
{
    int current_digit;
    int nb_rest;

    current_digit = nb % 10;
    nb_rest = nb / 10;
    if (nb_rest != 0) {
        print_digit(nb_rest);
    }
    my_putchar('0' + current_digit);
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    print_digit(nb);
    return 0;
}
