/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort
*/

#include <stddef.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/organized.h"

static int cmp(material *current, material *next, sort_params *sp)
{
    switch (sp->tag) {
        case TYPE:
            return cmp_alphabet(TYPES[current->type],
                TYPES[next->type], sp->reverse);
        case NAME:
            return cmp_alphabet(current->name, next->name, sp->reverse);
        case ID:
            return cmp_numeric(current->id, next->id, sp->reverse);
        default:
            return 1;
    }
}

static int cmp_and_swap(material *current, material *next, sort_params *sp)
{
    int sorted = cmp(current, next, sp);
    material *tmp;

    if (!sorted) {
        tmp = malloc(sizeof(material));
        tmp->id = current->id;
        tmp->type = current->type;
        tmp->name = current->name;
        current->id = next->id;
        current->type = next->type;
        current->name = next->name;
        next->id = tmp->id;
        next->type = tmp->type;
        next->name = tmp->name;
        free(tmp);
        return 1;
    }
    return 0;
}

static void bubble_sort(material **list, sort_params *sp)
{
    int swapped = 1;
    material *current;
    material *end = NULL;

    while (swapped) {
        swapped = 0;
        current = *list;
        while (current->next != end) {
            swapped = cmp_and_swap(current, current->next, sp) ? 1 : swapped;
            current = current->next;
        }
        end = current;
    }
}

static void sorting(material **list, sort_params **sps)
{
    sort_params *current = *sps;

    while (current != NULL) {
        bubble_sort(list, current);
        *sps = current->next;
        free(current);
        current = *sps;
    }
}

static int extract_args(sort_params **sp, char *first_arg, char *second_arg)
{
    (*sp)->next = NULL;
    (*sp)->tag = -1;
    for (int i = 0; i < SORT_TAGS_SIZE; i++) {
        if (!my_strcmp(SORT_TAGS[i], first_arg))
            (*sp)->tag = i;
    }
    if (((int) (*sp)->tag) == -1) {
        put_error("Invalid Tag!\n");
        return 84;
    }
    (*sp)->reverse = 0;
    if (second_arg != 0)
        (*sp)->reverse = my_strcmp(second_arg, SORT_RE_FLAG) ? 0 : 1;
    return 0;
}

static int get_sort_params(sort_params **sps, char **args)
{
    int i = 0;
    sort_params *sp;
    int error;

    while (args[i] != 0) {
        sp = malloc(sizeof(sort_params));
        error = extract_args(&sp, args[i], args[i + 1]);
        if (error != 0)
            return error;
        if (args[i + 1] != 0 && !my_strcmp(args[i + 1], SORT_RE_FLAG))
            i++;
        sp->next = *sps;
        *sps = sp;
        i++;
    }
    return 0;
}

int sort(void *data, char **args)
{
    material **list = (material **) data;
    sort_params *sps = NULL;
    int error = 0;

    if (args[0] == 0) {
        put_error("Error: Arguments expected for sort!\n");
        return 84;
    }
    error = get_sort_params(&sps, args);
    if (error != 0)
        return error;
    if (*list == NULL || (*list)->next == NULL)
        return 0;
    sorting(list, &sps);
    return 0;
}
