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