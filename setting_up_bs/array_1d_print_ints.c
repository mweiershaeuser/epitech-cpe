/*
** EPITECH PROJECT, 2023
** array_1d_print_chars
** File description:
** array_1d_print_chars
*/

#include "my.h"

void array_1d_print_ints(int const *arr, int size)
{
    for (int i = 0; i < size; i++) {
        my_put_nbr(arr[i]);
        my_putchar('\n');
    }
}
