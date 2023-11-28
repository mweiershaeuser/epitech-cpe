/*
** EPITECH PROJECT, 2023
** organized_bs
** File description:
** display_list
*/

#include <stddef.h>
#include "bootstrap.h"

void display_list(linked_list_t *begin, void (*disp_fct)())
{
    while (begin->next != NULL) {
        disp_fct(begin->data);
        begin = begin->next;
    }
    disp_fct(begin->data);
}
