/*
** EPITECH PROJECT, 2023
** array_1d_print_chars
** File description:
** array_1d_print_chars
*/

#include "my.h"

int array_2d_sum(int const **arr, int nb_rows, int nb_cols)
{
    int sum = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}
