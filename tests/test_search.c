#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
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

Test(secured, search_error01, .init = cr_redirect_stderr)
{
    char *return_value;

    return_value = ht_search(NULL, "Test");
    cr_assert_stderr_eq_str("Invalid input: Search impossible!\n");
    cr_assert_eq(return_value, 84);
}

Test(secured, search_error02, .init = cr_redirect_stderr)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));
    char *return_value;

    ht->table = NULL;
    return_value = ht_search(ht, "Test");
    cr_assert_stderr_eq_str("Invalid input: Search impossible!\n");
    cr_assert_eq(return_value, 84);
    free(ht);
}

Test(secured, search_error03, .init = cr_redirect_stderr)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    char *return_value;

    return_value = ht_search(ht, NULL);
    cr_assert_stderr_eq_str("Invalid input: Search impossible!\n");
    cr_assert_eq(return_value, 84);
    delete_hashtable(ht);
}
