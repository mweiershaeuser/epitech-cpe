/*
** EPITECH PROJECT, 2023
** organized
** File description:
** add
*/

#include <stddef.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/organized.h"

static int get_highest_id(material *list)
{
    int highest_number = 0;

    if (list == NULL)
        return 0;
    while (list->next != NULL) {
        if (list->id >= highest_number)
            highest_number = list->id;
        list = list->next;
    }
    return highest_number + 1;
}

static void extract_data(material *list, material **item,
    char *type, char *name)
{
    (*item)->id = get_highest_id(list);
    (*item)->name = malloc(sizeof(char) * my_strlen(name) + 1);
    my_strcpy((*item)->name, name);
    for (int i = 0; i < TYPES_SIZE; i++) {
        if (!my_strcmp(TYPES[i], type))
            (*item)->type = i;
    }
}

void add_single(material **list, char *type, char *name)
{
    material *new_material;

    new_material = malloc(sizeof(material));
    extract_data(*list, &new_material, type, name);
    if (*list == NULL) {
        *list = new_material;
    } else {
        new_material->next = *list;
        *list = new_material;
    }
    mini_printf("%s n°%d - \"%s\" added.\n", TYPES[new_material->type],
        new_material->id, new_material->name);
}

int add(void *data, char **args)
{
    material **list = (material **) data;
    int i = 0;

    while (args[i] != 0) {
        add_single(list, args[i], args[i + 1]);
        i = i + 2;
    }
    return 0;
}
