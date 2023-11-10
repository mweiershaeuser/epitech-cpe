/*
** EPITECH PROJECT, 2023
** fs_get_number_from_first_line
** File description:
** fs_get_number_from_first_line
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int fs_get_number_from_first_line(char const *filepath)
{
    char buffer[11];
    char *current = buffer;
    int fd = open(filepath, O_RDONLY);
    int res = 1;

    while (res != 0 && res != -1) {
        res = read(fd, current, 1);
        if (*current == '\n' || *current == '\0') {
            break;
        }
        current++;
    }
    *current = '\0';
    close(fd);
    return 0;
}
