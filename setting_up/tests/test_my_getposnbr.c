#include <criterion/criterion.h>
#include "../include/setting_up.h"

Test(setting_up, my_getposnbr_error)
{
    cr_assert_eq(my_getposnbr("-123"), -1);
    cr_assert_eq(my_getposnbr("12!3"), -1);
    cr_assert_eq(my_getposnbr("Hello"), -1);
    cr_assert_eq(my_getposnbr("123!"), -1);
}

Test(setting_up, my_getposnbr_return_nbr)
{
    cr_assert_eq(my_getposnbr("123"), 123);
    cr_assert_eq(my_getposnbr("000123"), 123);
    cr_assert_eq(my_getposnbr("0"), 0);
    cr_assert_eq(my_getposnbr("9"), 9);
    cr_assert_eq(my_getposnbr("10"), 10);
    cr_assert_eq(my_getposnbr("1000"), 1000);
}