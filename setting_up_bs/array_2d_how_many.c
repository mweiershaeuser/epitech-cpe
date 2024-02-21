/*
** EPITECH PROJECT, 2023
** array_1d_print_chars
** File description:
** array_1d_print_chars
*/

#include "my.h"

int array_2d_how_many(int const **arr, int nb_rows, int nb_cols, int number)
{
    int amount = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            amount += arr[i][j] == number ? 1 : 0;
        }
    }
    return amount;
}
