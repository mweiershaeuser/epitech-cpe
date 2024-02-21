/*
** EPITECH PROJECT, 2023
** organized_bs
** File description:
** put_error
*/

#include "unistd.h"
#include "my.h"

void put_error(char *msg)
{
    write(2, msg, my_strlen(msg));
}
