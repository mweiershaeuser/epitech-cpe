/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** Determines if a number is positive or negative.
*/

#include "../../include/my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
    return 0;
}
