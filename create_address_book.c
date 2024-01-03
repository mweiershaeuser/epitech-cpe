/*
** EPITECH PROJECT, 2023
** secured_bs
** File description:
** create_address_book
*/

#include <stdlib.h>
#include "my.h"
#include "bootstrap.h"

entry_t **create_address_book(int len)
{
    entry_t **book;

    book = malloc(sizeof(entry_t *) * len);
    for (int i = 0; i < len; i++) {
        book[i] = NULL;
    }
    my_putstr("address book created\n");
    return book;
}
