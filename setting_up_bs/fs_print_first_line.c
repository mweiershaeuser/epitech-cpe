/*
** EPITECH PROJECT, 2023
** fs_print_first_line
** File description:
** fs_print_first_line
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void fs_print_first_line(char const *filepath)
{
    char buffer[1];
    int fd = open(filepath, O_RDONLY);
    int res = 1;

    while (res != 0 && res != -1) {
        res = read(fd, buffer, 1);
        if (buffer[0] == '\n')
            break;
        my_putchar(buffer[0]);
    }
    close(fd);
}
