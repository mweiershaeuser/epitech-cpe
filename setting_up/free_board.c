/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** free_board
*/

#include <stdlib.h>
#include "include/setting_up.h"

void free_board(board *b)
{
    for (int i = 0; i < b->height; i++) {
        free(b->map[i]);
    }
    free(b->map);
    free(b);
}
