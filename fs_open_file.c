/*
** EPITECH PROJECT, 2023
** fs_open_file
** File description:
** fs_open_file
*/

#include <fcntl.h>
#include "my.h"

int fs_open_file(char const *filepath)
{
    int opened;

    opened = open(filepath, O_RDONLY);
    if (opened == -1) {
        my_putstr("FAILURE\n");
    } else {
        my_putstr("SUCCESS\n");
    }
    return opened;
}
