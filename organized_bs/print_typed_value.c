/*
** EPITECH PROJECT, 2023
** organized_bs
** File description:
** print_typed_value
*/

#include "bootstrap.h"
#include "my.h"
#include "organized_bs.h"

static void print_player(player_t *p)
{
    my_putstr(p->name);
    my_putstr(": lvl.");
    my_put_nbr(p->lvl);
}

int print_typed_value(void *data, type_t type)
{
    switch (type) {
        case INTEGER:
            my_put_nbr(*((int *) data));
            break;
        case CHAR:
            my_putchar(*((char *) data));
            break;
        case STRING:
            my_putstr(((char *) data));
            break;
        case PLAYER:
            print_player((player_t *) data);
            break;
        default:
            put_error("Type could not be identified.\n");
            return 84;
            break;
    }
    my_putchar('\n');
    return 0;
}
