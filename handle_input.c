/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** handling_input
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/setting_up.h"

static char *handle_input_file(char *filename)
{
    return 0;
}

static char *handle_input_generator(char *size, char *pattern)
{
    char *gen_board;
    int size_n = my_getposnbr(size);
    int pat_cnt = 0;
    int pat_len = my_strlen(pattern);
    int i = 0;
    int j = 0;

    gen_board = malloc(sizeof(char) * (size_n + 1) * size_n + 1);
    for (i = 0; i < size_n; i++) {
        for (j = 0; j < size_n; j++) {
            gen_board[i * (size_n + 1) + j] = pattern[pat_cnt];
            pat_cnt = pat_cnt >= (pat_len - 1) ? 0 : pat_cnt + 1;
        }
        gen_board[i * (size_n + 1) + j] = '\n';
    }
    gen_board[(size_n + 1) * size_n] = '\0';
    return gen_board;
}

char *handle_input(int argc, char **argv)
{
    if (argc <= 1 || argc > 3) {
        put_error("Incorrect Arguments!\n");
        return 0;
    }
    if (argc == 2) {
        return handle_input_file(argv[1]);
    } else {
        return handle_input_generator(argv[1], argv[2]);
    }
}
