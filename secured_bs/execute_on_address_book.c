/*
** EPITECH PROJECT, 2023
** secured_bs
** File description:
** execute_on_address_book
*/

#include "bootstrap.h"

void execute_on_address_book(entry_t **address_book,
    int len, void (*execute) (entry_t *))
{
    for (int i = 0; i < len; i++) {
        execute(address_book[i]);
    }
}
