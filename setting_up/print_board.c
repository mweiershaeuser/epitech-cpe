/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** print_board
*/

#include "include/my.h"
#include "include/setting_up.h"

void print_board(board *b)
{
    for (int i = 0; i < b->height; i++) {
        for (int j = 0; j < b->width; j++) {
            my_putchar(b->map[i][j]);
        }
        my_putchar('\n');
    }
}
