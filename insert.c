/*
** EPITECH PROJECT, 2024
** secured
** File description:
** insert.c
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/hashtable.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    entry *entry;
    int index = 0;

    entry = malloc(sizeof(entry));
    entry->value = malloc(sizeof(char) * my_strlen(value) + 1);
    my_strcpy(entry->value, value);
    entry->hash = ht->hash(key, ht->size);
    index = entry->hash % ht->size;
    entry->next = ht->table[index];
    ht->table[index] = entry;
    return 0;
}
