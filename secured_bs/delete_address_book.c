/*
** EPITECH PROJECT, 2023
** secured_bs
** File description:
** delete_address_book
*/

#include <stdlib.h>
#include "my.h"
#include "bootstrap.h"

void delete_address_book(entry_t **address_book, int len)
{
    for (int i = 0; i < len; i++) {
        if (address_book[i]) {
            free(address_book[i]->name);
            free(address_book[i]->phone_number);
            free(address_book[i]);
        }
    }
    free(address_book);
    my_putstr("address book deleted\n");
}
