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
    mini_printf("%s n°%d - \"%s\"\n", TYPES[item->type], item->id, item->name);
}

int disp(void *data, char **args)
{
    material *list = *((material **) data);

    if (args[0] != 0) {
        put_error("Error: no arguments allowed for disp!\n");
        return 84;
    }
    if (list == NULL)
        return 0;
    while (list->next != NULL) {
        print_material(list);
        list = list->next;
    }
    print_material(list);
    return 0;
}
