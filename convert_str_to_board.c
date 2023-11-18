/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** convert_str_to_board
*/

#include <stdlib.h>
#include "include/setting_up.h"

static void count_size(board *b, char *str)
{
    int counter = 0;

    b->width = 0;
    b->height = 0;
    while (str[counter] != '\0') {
        if (str[counter] == '\n' && !b->width) {
            b->width = counter;
        }
        if (str[counter] == '\n') {
            b->height++;
        }
        counter++;
    }
}

static char **alloc_map(int nb_rows, int nb_cols)
{
    char **arr;

    arr = malloc(sizeof(char *) * nb_rows);
    for (int i = 0; i < nb_rows; i++) {
        arr[i] = malloc(sizeof(char) * nb_cols);
    }
    return arr;
}

static void get_map(board *b, char *str)
{
    b->map = alloc_map(b->height, b->width);
    for (int i = 0; i < b->height; i++) {
        for (int j = 0; j < b->width; j++) {
            b->map[i][j] = str[i * (b->width + 1) + j];
        }
    }
}

board *convert_str_to_board(char *str)
{
    board *b;

    b = malloc(sizeof(board));
    count_size(b, str);
    get_map(b, str);
    return b;
}
