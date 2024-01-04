/*
** EPITECH PROJECT, 2024
** secured
** File description:
** dump.c
*/

#include <stddef.h>
#include "include/hashtable.h"
#include "include/my.h"

void ht_dump(hashtable_t *ht)
{
    entry *current;

    if (ht == NULL || ht->table == NULL) {
        mini_printf("Hash table is empty or invalid.\n");
        return;
    }
    mini_printf("[0]:\n");
    for (int i = 0; i < ht->size; ++i) {
        mini_printf("[%d]:\n", i);
        current = ht->table[i];
        while (current != NULL) {
            mini_printf("%s\n", current->value);
            current = current->next;
        }
    }
}
