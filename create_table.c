/*
** EPITECH PROJECT, 2024
** secured
** File description:
** create.c
*/

#include "hashtable.h"
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *table = (hashtable_t *)malloc(sizeof(hashtable_t));

    if (table == NULL) {
        return NULL;
    }
    table->size = len;
    table->table = (entry *)malloc(len * sizeof(entry));
    if (table->table == NULL) {
        free(table);
        return NULL;
    }
    for (int i = 0; i < len; ++i) {
        table->table[i].hash = -1;
        table->table[i].value = NULL;
        table->table[i].next = NULL;
    }
    table->hash = hash;
    return table;
}
