/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** handling_input
*/

#include "include/my.h"
#include "include/setting_up.h"

static char *handle_input_file(char *filename)
{
    return 0;
}

static char *handle_input_generator(char *size, char *pattern)
{
    return 0;
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
