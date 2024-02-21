/*
** EPITECH PROJECT, 2024
** secured
** File description:
** delete_table.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/hashtable.h"

static void free_entry(entry *current)
{
    entry *temp = NULL;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->value);
        free(temp);
    }
}

static void free_table(entry **table, int size)
{
    for (int i = 0; i < size; ++i) {
        free_entry(table[i]);
        table[i] = NULL;
    }
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    if (ht->table != NULL) {
        free_table(ht->table, ht->size);
        free(ht->table);
        ht->table = NULL;
    }
    free(ht);
}
