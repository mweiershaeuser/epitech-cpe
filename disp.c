/*
** EPITECH PROJECT, 2023
** organized
** File description:
** disp
*/

#include <stddef.h>
#include "include/my.h"
#include "include/organized.h"

static void print_material(material *item)
{
    if (item == NULL)
        return;
    mini_printf("n°%d - \"%s\"\n", item->id, item->name);
}

int disp(void *data, char **args)
{
    material *list = (material *) data;

    (void) args;
    while (list->next != NULL) {
        print_material(list);
        list = list->next;
    }
    print_material(list);
    return 0;
}
