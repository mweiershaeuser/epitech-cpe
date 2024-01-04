/*
** EPITECH PROJECT, 2024
** secured
** File description:
** insert.c
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/hashtable.h"

static entry *find_entry(hashtable_t *ht, int hash, int index)
{
    entry *current = ht->table[index];

    while (current != NULL) {
        if (current->hash == hash)
            break;
        current = current->next;
    }
    return current;
}

static entry *create_entry(hashtable_t *ht, char *key, char *value)
{
    entry *entry;
    int index;

    entry = malloc(sizeof(entry));
    entry->value = malloc(sizeof(char) * my_strlen(value) + 1);
    my_strcpy(entry->value, value);
    entry->hash = ht->hash(key, ht->size);
    index = entry->hash % ht->size;
    entry->next = ht->table[index];
    ht->table[index] = entry;
    return entry;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    entry *entry;
    int hash;
    int index;

    hash = ht->hash(key, ht->size);
    index = hash % ht->size;
    entry = find_entry(ht, hash, index);
    if (entry != NULL) {
        my_strcpy(entry->value, value);
    } else {
        entry = create_entry(ht, key, value);
    }
    return 0;
}
