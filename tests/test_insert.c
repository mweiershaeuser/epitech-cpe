#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

Test(secured, insert_single_new_entry)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_insert(ht, "pomme", "compote");
    cr_assert_eq(ht->table[15]->hash, 271086885);
    cr_assert_str_eq(ht->table[15]->value, "compote");
    delete_hashtable(ht);
}

Test(secured, insert_multiple_new_entries)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_insert(ht, "pomme", "compote");
    ht_insert(ht, "poire", "tarte");
    ht_insert(ht, "framboise", "macaron");
    cr_assert_str_eq(ht->table[15]->value, "compote");
    cr_assert_str_eq(ht->table[24]->value, "macaron");
    cr_assert_str_eq(ht->table[24]->next->value, "tarte");
    delete_hashtable(ht);
}

Test(secured, insert_update_entry01)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_insert(ht, "pomme", "compote");
    ht_insert(ht, "poire", "tarte");
    ht_insert(ht, "framboise", "macaron");
    cr_assert_str_eq(ht->table[15]->value, "compote");
    cr_assert_str_eq(ht->table[24]->value, "macaron");
    cr_assert_str_eq(ht->table[24]->next->value, "tarte");
    ht_insert(ht, "framboise", "glace");
    cr_assert_str_eq(ht->table[24]->value, "glace");
    delete_hashtable(ht);
}

Test(secured, insert_update_entry02)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_insert(ht, "pomme", "compote");
    ht_insert(ht, "poire", "tarte");
    ht_insert(ht, "framboise", "macaron");
    cr_assert_str_eq(ht->table[15]->value, "compote");
    cr_assert_str_eq(ht->table[24]->value, "macaron");
    cr_assert_str_eq(ht->table[24]->next->value, "tarte");
    ht_insert(ht, "poire", "glace");
    cr_assert_str_eq(ht->table[24]->next->value, "glace");
    delete_hashtable(ht);
}
