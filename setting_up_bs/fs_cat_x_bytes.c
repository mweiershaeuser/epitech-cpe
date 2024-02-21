/*
** EPITECH PROJECT, 2023
** fs_cat_x_bytes
** File description:
** fs_cat_x_bytes
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void fs_cat_x_bytes(char const *filepath, int x)
{
    char buffer[x + 1];
    int fd = open(filepath, O_RDONLY);

    read(fd, buffer, x);
    buffer[x] = '\0';
    my_putstr(buffer);
    close(fd);
}
