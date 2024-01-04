/*
** EPITECH PROJECT, 2024
** secured
** File description:
** dump.c
*/

#include "include/hashtable.h"
#include <stddef.h>

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL || ht->table == NULL) {
        my_put_error("Hash table is empty or invalid.\n");
        return 84;
    }
}
