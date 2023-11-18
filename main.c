/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** main
*/

#include <stdlib.h>
#include "include/setting_up.h"

static void free_board(board *b)
{
    for (int i = 0; i < b->height; i++) {
        free(b->map[i]);
    }
    free(b->map);
    free(b);
}

int main(int argc, char **argv)
{
    char *board_str = handle_input(argc, argv);
    board *b;

    if (board_str == 0)
        return 84;
    b = convert_str_to_board(board_str);
    print_board(b);
    free(board_str);
    free_board(b);
    return 0;
}
