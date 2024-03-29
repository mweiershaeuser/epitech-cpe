/*
** EPITECH PROJECT, 2023
** organized
** File description:
** del
*/

#include <stddef.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/organized.h"

void del_item(material **previous_next, material *current)
{
    *previous_next = current->next;
    mini_printf("%s n°%d - \"%s\" deleted.\n", TYPES[current->type],
        current->id, current->name);
    free(current->name);
    free(current);
}

void del_single(material **list, int id)
{
    material *previous = *list;
    material *current = (*list)->next;

    if (previous->id == id) {
        del_item(list, previous);
        return;
    }
    while (current->next != NULL) {
        if (current->id == id) {
            del_item(&(previous->next), current);
            return;
        }
        previous = current;
        current = current->next;
    }
    if (current->id == id)
        del_item(&(previous->next), current);
}

int del(void *data, char **args)
{
    material **list = (material **) data;
    int i = 0;
    int number = 0;

    if (args[i] == 0)
        return 84;
    if (*list == NULL)
        return 0;
    while (args[i] != 0) {
        number = my_getposnbr(args[i]);
        if (number < 0) {
            put_error("Invalid ID!\n");
            return 84;
        }
        del_single(list, number);
        i++;
    }
    return 0;
}
