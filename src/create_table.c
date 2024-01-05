/*
** EPITECH PROJECT, 2024
** secured
** File description:
** create.c
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht;

    if (len <= 0) {
        my_put_error("Invalid input: length has to be strictly positive!\n");
        return (hashtable_t *) 84;
    }
    if (!hash) {
        my_put_error("Invalid input: no hash function given!\n");
        return (hashtable_t *) 84;
    }
    ht = malloc(sizeof(hashtable_t));
    ht->size = len;
    ht->hash = hash;
    ht->table = malloc(sizeof(entry *) * len);
    for (int i = 0; i < len; ++i) {
        (ht->table)[i] = NULL;
    }
    return ht;
}
