#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "../include/hashtable.h"

Test(secured, dump_success, .init = cr_redirect_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    ht_insert(ht, "pomme", "compote");
    ht_insert(ht, "poire", "tarte");
    ht_insert(ht, "framboise", "macaron");
    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n> 271086885 - compote\n[2]:\n> 1211190534 - macaron\n> 271082694 - tarte\n[3]:\n");
    delete_hashtable(ht);
}

Test(secured, dump_error01, .init = cr_redirect_stderr)
{
    ht_dump(NULL);
    cr_assert_stderr_eq_str("Hash table is empty or invalid.\n");
}

Test(secured, dump_error02, .init = cr_redirect_stderr)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    ht->table = NULL;
    ht_dump(ht);
    cr_assert_stderr_eq_str("Hash table is empty or invalid.\n");
    free(ht);
}
