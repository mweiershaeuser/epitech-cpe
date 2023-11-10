/*
** EPITECH PROJECT, 2023
** fs_
** File description:
** fs_open_file
*/

#include <unistd.h>
#include "my.h"

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int res = read(fd, buffer, size);

    if (res == -1) {
        my_putstr("read failed\n");
        return;
    }
    if (res == 0) {
        my_putstr("read has nothing more to read\n");
        return;
    }
    if (res < size) {
        my_putstr("read didn’t complete the entire buffer\n");
        return;
    }
    if (res == size) {
        my_putstr("read completed the entire buffer\n");
        return;
    }
}
