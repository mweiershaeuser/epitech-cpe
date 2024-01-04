/*
** EPITECH PROJECT, 2024
** secured
** File description:
** search.c
*/

#include "include/hashtable.h"
#include "include/secured.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int hash = ht->hash(key, ht->size);
    int index = hash % ht->size;
    entry *entry = find_entry(ht, hash, index);

    if (entry) {
        return entry->value;
    } else {
        return 0;
    }
}
