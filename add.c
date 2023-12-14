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

static int extract_data(material *list, material **item,
    char *type, char *name)
{
    (*item)->type = -1;
    for (int i = 0; i < TYPES_SIZE; i++) {
        if (!my_strcmp(TYPES[i], type))
            (*item)->type = i;
    }
    if ((*item)->type == -1) {
        put_error("Invalid Type!\n");
        return 84;
    }
    (*item)->id = get_highest_id(list);
    (*item)->name = malloc(sizeof(char) * my_strlen(name) + 1);
    my_strcpy((*item)->name, name);
    return 0;
}

int add_single(material **list, char *type, char *name)
{
    material *new_material;
    int error = 0;

    new_material = malloc(sizeof(material));
    error = extract_data(*list, &new_material, type, name);
    if (error != 0)
        return 84;
    if (*list == NULL) {
        *list = new_material;
    } else {
        new_material->next = *list;
        *list = new_material;
    }
    mini_printf("%s n°%d - \"%s\" added.\n", TYPES[new_material->type],
        new_material->id, new_material->name);
    return 0;
}

int add(void *data, char **args)
{
    material **list = (material **) data;
    int i = 0;
    int error = 0;

    if (args[0] == 0) {
        put_error("Error: add requires arguments!\n");
        return 84;
    }
    while (args[i] != 0) {
        if (args[i + 1] == 0) {
            put_error("Invalid amount of arguments!\n");
            return 84;
        }
        error = add_single(list, args[i], args[i + 1]);
        if (error != 0)
            return 84;
        i = i + 2;
    }
    return 0;
}
