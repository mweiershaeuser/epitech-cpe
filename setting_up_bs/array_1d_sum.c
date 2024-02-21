/*
** EPITECH PROJECT, 2023
** array_1d_print_chars
** File description:
** array_1d_print_chars
*/

#include "my.h"

int array_1d_sum(int const *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
