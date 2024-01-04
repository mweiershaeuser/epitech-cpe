#include <criterion/criterion.h>
#include "../include/hashtable.h"

Test(secured, search_success)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_insert(ht, "pomme", "compote");
    ht_insert(ht, "poire", "tarte");
    ht_insert(ht, "framboise", "macaron");
    cr_assert_str_eq(ht_search(ht, "pomme"), "compote");
    cr_assert_str_eq(ht_search(ht, "poire"), "tarte");
    cr_assert_str_eq(ht_search(ht, "framboise"), "macaron");
    delete_hashtable(ht);
}

Test(secured, search_no_success)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    ht_insert(ht, "pomme", "compote");
    ht_insert(ht, "poire", "tarte");
    ht_insert(ht, "framboise", "macaron");
    cr_assert_eq(ht_search(ht, "ananas"), 0);
    delete_hashtable(ht);
}
