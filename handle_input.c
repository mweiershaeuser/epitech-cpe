/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** handle_input
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"
#include "include/setting_up.h"

static int open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        put_error("Error opening file.\n");
        return -1;
    }
    return fd;
}

static int get_number_from_first_line(int fd)
{
    char buffer[11];
    char *current = buffer;
    int res = 1;

    while (res != 0 && res != -1) {
        res = read(fd, current, 1);
        if (*current == '\n' || *current == '\0') {
            break;
        }
        current++;
    }
    *current = '\0';
    return my_getposnbr(buffer);
}

static int get_width_of_board(int fd)
{
    int width = 0;
    char c;
    int res = 1;

    while (res != 0 && res != -1) {
        res = read(fd, &c, 1);
        if (c == '\n' || c == '\0') {
            break;
        }
        width++;
    }
    return width;
}

static void skip_first_line(int fd)
{
    char c;
    int res = 1;

    while (res != 0 && res != -1) {
        res = read(fd, &c, 1);
        if (c == '\n' || c == '\0') {
            break;
        }
    }
}

static char *get_board_from_file(int fd, int height, int width)
{
    char *board_str;
    int length = height * (width + 1);

    board_str = malloc(sizeof(char) * (length + 1));
    read(fd, board_str, length);
    board_str[length] = '\0';
    return board_str;
}

static char *handle_input_file(char const *filepath)
{
    char *board_str;
    int fd = open_file(filepath);
    int height = 0;
    int width = 0;

    if (fd == -1)
        return 0;
    height = get_number_from_first_line(fd);
    width = get_width_of_board(fd);
    close(fd);
    fd = open_file(filepath);
    skip_first_line(fd);
    board_str = get_board_from_file(fd, height, width);
    close(fd);
    return board_str;
}

static int validate_gen_input(int size_n, char *pattern)
{
    int pattern_len = my_strlen(pattern);

    if (size_n <= 0) {
        put_error("The given size is invalid!\n");
        return 0;
    }
    for (int i = 0; i < pattern_len; i++) {
        if (!(pattern[i] == '.' || pattern[i] == 'o')) {
            put_error("The given pattern is invalid!\n");
            return 0;
        }
    }
    return 1;
}

static char *handle_input_generator(char *size, char *pattern)
{
    char *gen_board;
    int size_n = my_getposnbr(size);
    int pat_cnt = 0;
    int pat_len = my_strlen(pattern);
    int i = 0;
    int j = 0;

    if (!validate_gen_input(size_n, pattern))
        return 0;
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
