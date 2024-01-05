/*
** EPITECH PROJECT, 2024
** secured
** File description:
** find_entry.c
*/

#include <stddef.h>
#include "../include/hashtable.h"

entry *find_entry(hashtable_t *ht, int hash, int index)
{
    entry *current = ht->table[index];

    while (current != NULL) {
        if (current->hash == hash)
            break;
        current = current->next;
    }
    return current;
}
