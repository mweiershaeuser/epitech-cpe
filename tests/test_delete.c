#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

Test(secured, delete_single_entry)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_insert(ht, "pomme", "compote");
    ht_insert(ht, "poire", "tarte");
    ht_insert(ht, "framboise", "macaron");
    cr_assert_str_eq(ht->table[15]->value, "compote");
    cr_assert_str_eq(ht->table[24]->value, "macaron");
    cr_assert_str_eq(ht->table[24]->next->value, "tarte");
    ht_delete(ht, "pomme");
    cr_assert_eq(ht->table[15], NULL);
    delete_hashtable(ht);
}

Test(secured, delete_first_entry_in_list)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_insert(ht, "pomme", "compote");
    ht_insert(ht, "poire", "tarte");
    ht_insert(ht, "framboise", "macaron");
    cr_assert_str_eq(ht->table[15]->value, "compote");
    cr_assert_str_eq(ht->table[24]->value, "macaron");
    cr_assert_str_eq(ht->table[24]->next->value, "tarte");
    ht_delete(ht, "framboise");
    cr_assert_str_eq(ht->table[24]->value, "tarte");
    delete_hashtable(ht);
}

Test(secured, delete_second_entry_in_list)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_insert(ht, "pomme", "compote");
    ht_insert(ht, "poire", "tarte");
    ht_insert(ht, "framboise", "macaron");
    cr_assert_str_eq(ht->table[15]->value, "compote");
    cr_assert_str_eq(ht->table[24]->value, "macaron");
    cr_assert_str_eq(ht->table[24]->next->value, "tarte");
    ht_delete(ht, "poire");
    cr_assert_str_eq(ht->table[24]->value, "macaron");
    delete_hashtable(ht);
}

Test(secured, delete_not_found, .init = cr_redirect_stderr)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_delete(ht, "ananas");
    cr_assert_stderr_eq_str("Error: Key wasn't found in hashtable.\n");
    delete_hashtable(ht);
}
