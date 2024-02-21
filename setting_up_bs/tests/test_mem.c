#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../setting_up_bs.h"

Test(setting_up_bs, mem_1_1)
{
    char *str1 = "Hello ";
    char *str2 = "World!";
    char *cat;

    cat = mem_alloc(str1, str2);
    cr_assert_str_eq(cat, "Hello World!");
}

Test(setting_up_bs, mem_2_and_3_1)
{
    char **arr = mem_alloc_2d_array(2, 4);
    arr[0] = "Hi ";
    arr[1] = "du!";
    char **arr_cpy = mem_dup_2d_array(arr, 2, 4);
    cr_assert_str_eq(arr_cpy[0], "Hi ");
    cr_assert_str_eq(arr_cpy[1], "du!");
    cr_assert_neq(&arr, &arr_cpy);
}
