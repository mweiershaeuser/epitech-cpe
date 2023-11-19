/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** put_square
*/

#include "include/setting_up.h"

void put_square(board *b, square *s)
{
    for (int i = s->y_pos; i < s->y_pos + s->size; i++) {
        for (int j = s->x_pos; j < s->x_pos + s->size; j++) {
            b->map[i][j] = 'x';
        }
    }
}