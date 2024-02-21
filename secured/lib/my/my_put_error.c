/*
** EPITECH PROJECT, 2023
** my_put_error
** File description:
** my_put_error
*/

#include "unistd.h"
#include "../../include/my.h"

void my_put_error(char *msg)
{
    write(2, msg, my_strlen(msg));
}
