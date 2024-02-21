/*
** EPITECH PROJECT, 2023
** secured_bs
** File description:
** create_address
*/

#include <stdlib.h>
#include "my.h"
#include "bootstrap.h"

entry_t *create_address(const char *name, const char *phone_number)
{
    entry_t *entry = malloc(sizeof(entry_t));

    entry->name = malloc(sizeof(char) * my_strlen(name) + 1);
    entry->phone_number = malloc(sizeof(char) * my_strlen(phone_number) + 1);
    my_strcpy(entry->name, name);
    my_strcpy(entry->phone_number, phone_number);
    return entry;
}
