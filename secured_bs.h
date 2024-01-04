/*
** EPITECH PROJECT, 2023
** secured_bs
** File description:
** Header
*/

#include "bootstrap.h"

#ifndef SECURED_BS_H
    #define SECURED_BS_H
entry_t **create_address_book(int len);
entry_t *create_address(const char *name, const char *phone_number);
#endif
