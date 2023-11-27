/*
** EPITECH PROJECT, 2023
** organized_bs
** File description:
** print_typed_value
*/

#include "bootstrap.h"
#include "my.h"

int print_typed_value(void *data, type_t type)
{
    switch (type) {
        case INTEGER:
            my_put_nbr(*((int *)data));
            break;
        case CHAR:
            my_putchar(*((char *)data));
            break;
        case STRING:
            my_putstr(((char *)data));
            break;
        case PLAYER:
            my_putstr(((player_t *)data)->name);
            my_putstr(": lvl.");
            my_put_nbr(((player_t *)data)->lvl);
            break;
        default:
            break;
    }
    my_putchar('\n');
    return 0;
}
