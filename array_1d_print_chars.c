/*
** EPITECH PROJECT, 2023
** array_1d_print_chars
** File description:
** array_1d_print_chars
*/

#include "my.h"

void array_1d_print_chars(char const *arr)
{
    while (*arr != '\0') {
        my_putchar(*arr);
        my_putchar('\n');
        arr++;
    }
}