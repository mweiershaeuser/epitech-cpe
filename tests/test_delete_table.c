#include <criterion/criterion.h>
#include "../include/hashtable.h"

Test(secured, hash_delete_table)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    delete_hashtable(ht);
}
