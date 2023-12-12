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
            highest_number = list->id + 1;
        list = list->next;
    }
    return highest_number;
}

static void extract_data(material *list, material **item, char **args)
{
    (*item)->id = get_highest_id(list);
    (*item)->name = malloc(sizeof(char) * my_strlen(args[1]) + 1);
    my_strcpy((*item)->name, args[1]);
    for (int i = 0; i < TYPES_SIZE; i++) {
        if (!my_strcmp(TYPES[i], args[0]))
            (*item)->type = i;
    }
}

int add(void *data, char **args)
{
    material **list = (material **) data;
    material *new_material;

    new_material = malloc(sizeof(material));
    extract_data(*list, &new_material, args);
    if (*list == NULL) {
        *list = new_material;
    } else {
        new_material->next = *list;
        *list = new_material;
    }
    return 0;
}
