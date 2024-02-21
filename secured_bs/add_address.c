/*
** EPITECH PROJECT, 2023
** secured_bs
** File description:
** add_address
*/

#include "my.h"
#include "bootstrap.h"
#include "secured_bs.h"

void add_address(entry_t **address_book, int len,
    const char *name, const char *phone_number)
{
    for (int i = 0; i < len; i++) {
        if (!address_book[i]) {
            address_book[i] = create_address(name, phone_number);
            my_putstr("new address added\n");
            return;
        }
    }
    my_putstr("add_address: not enough capacity to store new address\n");
}
