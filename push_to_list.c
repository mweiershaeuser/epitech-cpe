/*
** EPITECH PROJECT, 2023
** organized_bs
** File description:
** push_to_list
*/

#include <stdlib.h>
#include "bootstrap.h"
#include "my.h"
#include "organized_bs.h"

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *node;

    node = malloc(sizeof(linked_list_t));
    node->data = data;
    node->next = *begin;
    *begin = node;
}