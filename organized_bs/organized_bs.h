/*
** EPITECH PROJECT, 2023
** organized_bs
** File description:
** Header for the Organized Bootstrap
*/

#include "bootstrap.h"

#ifndef ORGANIZED_BS_H
    #define ORGANIZED_BS_H
void put_error(char *msg);
int print_typed_value(void *data, type_t type);
void push_to_list(linked_list_t **begin, void *data);
void display_list(linked_list_t *begin, void (*disp_fct)());
#endif
