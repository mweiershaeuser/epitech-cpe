/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include <stdlib.h>
#include "include/setting_up.h"

int setting_up(int argc, char **argv)
{
    char *board_str = handle_input(argc, argv);
    board *b;
    square *s;

    if (board_str == 0)
        return 84;
    b = convert_str_to_board(board_str);
    s = get_largest_square(b);
    put_square(b, s);
    print_board(b);
    free(board_str);
    free(s);
    free_board(b);
    return 0;
}
