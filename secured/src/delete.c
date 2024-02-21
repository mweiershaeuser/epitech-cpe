/*
** EPITECH PROJECT, 2024
** secured
** File description:
** delete.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/hashtable.h"
#include "../include/my.h"

static int delete_entry(hashtable_t *ht,
    entry *prev, entry *current, int index)
{
    if (prev == NULL) {
        ht->table[index] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current->value);
    free(current);
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hash;
    int index;
    entry *prev;
    entry *current;

    if (!ht || !(ht->table) || !key)
        return 84;
    hash = ht->hash(key, ht->size);
    index = hash % ht->size;
    prev = NULL;
    current = ht->table[index];
    while (current != NULL) {
        if (current->hash == hash)
            return delete_entry(ht, prev, current, index);
        prev = current;
        current = current->next;
    }
    my_put_error("Error: Key wasn't found in hashtable.\n");
    return 84;
}
