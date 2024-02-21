#include <criterion/criterion.h>
#include <stdlib.h>
#include "../include/hashtable.h"

Test(secured, delete_table01)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    delete_hashtable(ht);
}

Test(secured, delete_table02)
{
    delete_hashtable(NULL);
}

Test(secured, delete_table03)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    ht->table = NULL;
    delete_hashtable(ht);
}
