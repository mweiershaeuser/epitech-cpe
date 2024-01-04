#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

Test(secured, create_table_assign_size)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    cr_assert_eq(ht->size, 30);
    delete_hashtable(ht);
}

Test(secured, create_table_assign_hash_function)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    cr_assert_eq(ht->hash("Hello", 1), 223289563);
    delete_hashtable(ht);
}

Test(secured, create_table_allocate_table)
{
    hashtable_t *ht = new_hashtable(&hash, 30);
    cr_assert_eq((ht->table)[29], NULL);
    delete_hashtable(ht);
}

Test(secured, create_table_error_invalid_length01, .init = cr_redirect_stderr)
{
    hashtable_t *ht = new_hashtable(&hash, 0);
    cr_assert_eq(ht, 84);
    cr_assert_stderr_eq_str("Invalid input: length has to be strictly positive!\n");
}

Test(secured, create_table_error_invalid_length02, .init = cr_redirect_stderr)
{
    hashtable_t *ht = new_hashtable(&hash, -20);
    cr_assert_eq(ht, 84);
    cr_assert_stderr_eq_str("Invalid input: length has to be strictly positive!\n");
}

Test(secured, create_table_error_invalid_hash_function, .init = cr_redirect_stderr)
{
    hashtable_t *ht = new_hashtable(NULL, 30);
    cr_assert_eq(ht, 84);
    cr_assert_stderr_eq_str("Invalid input: no hash function given!\n");
}
