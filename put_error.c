/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** put_error
*/

#include "unistd.h"
#include "include/my.h"

void put_error(char *msg)
{
    write(2, msg, my_strlen(msg));
}
