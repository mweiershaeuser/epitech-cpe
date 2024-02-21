/*
** EPITECH PROJECT, 2023
** mem_alloc_2d_array
** File description:
** mem_alloc_2d_array
*/

#include <stdlib.h>
#include "my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr;

    arr = malloc(sizeof(char *) * nb_rows);
    for (int i = 0; i < nb_rows; i++) {
        arr[i] = malloc(sizeof(char) * nb_cols);
    }
    return arr;
}
