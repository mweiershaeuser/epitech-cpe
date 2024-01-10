/*
** EPITECH PROJECT, 2024
** secured
** File description:
** search.c
*/

#include "../include/my.h"
#include "../include/hashtable.h"
#include "../include/secured.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int hash;
    int index;
    entry *entry;

    if (!ht || !(ht->table) || !key) {
        my_put_error("Invalid input: Search impossible!\n");
        return (char *) 84;
    }
    hash = ht->hash(key, ht->size);
    index = hash % ht->size;
    entry = find_entry(ht, hash, index);
    if (entry) {
        return entry->value;
    } else {
        return 0;
    }
}
