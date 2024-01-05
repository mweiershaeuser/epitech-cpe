/*
** EPITECH PROJECT, 2024
** secured
** File description:
** dump.c
*/

#include <stddef.h>
#include "../include/hashtable.h"
#include "../include/my.h"

void ht_dump(hashtable_t *ht)
{
    entry *current;

    if (ht == NULL || ht->table == NULL) {
        my_put_error("Hash table is empty or invalid.\n");
        return;
    }
    for (int i = 0; i < ht->size; ++i) {
        mini_printf("[%d]:\n", i);
        current = ht->table[i];
        while (current != NULL) {
            mini_printf("> %d - %s\n", current->hash, current->value);
            current = current->next;
        }
    }
}
