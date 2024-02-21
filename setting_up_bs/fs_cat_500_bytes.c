/*
** EPITECH PROJECT, 2023
** fs_cat_500_bytes
** File description:
** fs_cat_500_bytes
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void fs_cat_500_bytes(char const *filepath)
{
    char buffer[501] = "";
    int fd = open(filepath, O_RDONLY);

    read(fd, buffer, 500);
    buffer[500] = '\0';
    my_putstr(buffer);
    close(fd);
}
