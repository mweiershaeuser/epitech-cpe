/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** main
*/

#include <stdlib.h>
#include "include/setting_up.h"

int main(int argc, char **argv)
{
    char *board_str = handle_input(argc, argv);

    if (board_str == 0)
        return 84;
    free(board_str);
    return 0;
}
