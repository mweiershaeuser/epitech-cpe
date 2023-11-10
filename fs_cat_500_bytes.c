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
    char buffer[500] = "";
    int fd = open(filepath, O_RDONLY);

    read(fd, buffer, 500);
    close(fd);
    my_putstr(buffer);
}
