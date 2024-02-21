#include <criterion/criterion.h>
#include "../include/organized.h"

Test(organized, cmp_numeric01)
{
    int sort = cmp_numeric(1, 2, 0);
    cr_assert_eq(sort, 1);
}

Test(organized, cmp_numeric02)
{
    int sort = cmp_numeric(2, 1, 0);
    cr_assert_eq(sort, 0);
}

Test(organized, cmp_numeric03)
{
    int sort = cmp_numeric(1, 2, 1);
    cr_assert_eq(sort, 0);
}

Test(organized, cmp_numeric04)
{
    int sort = cmp_numeric(2, 1, 1);
    cr_assert_eq(sort, 1);
}

Test(organized, cmp_alphabet01)
{
    int sort = cmp_alphabet("abc", "acb", 0);
    cr_assert_eq(sort, 1);
}

Test(organized, cmp_alphabet02)
{
    int sort = cmp_alphabet("acb", "abc", 0);
    cr_assert_eq(sort, 0);
}

Test(organized, cmp_alphabet03)
{
    int sort = cmp_alphabet("abc", "acb", 1);
    cr_assert_eq(sort, 0);
}

Test(organized, cmp_alphabet04)
{
    int sort = cmp_alphabet("acb", "abc", 1);
    cr_assert_eq(sort, 1);
}

Test(organized, cmp_alphabet05)
{
    int sort = cmp_alphabet("abc", "abcd", 0);
    cr_assert_eq(sort, 1);
}

Test(organized, cmp_alphabet06)
{
    int sort = cmp_alphabet("abcd", "abc", 0);
    cr_assert_eq(sort, 0);
}

Test(organized, cmp_alphabet07)
{
    int sort = cmp_alphabet("abc", "abcd", 1);
    cr_assert_eq(sort, 0);
}

Test(organized, cmp_alphabet08)
{
    int sort = cmp_alphabet("abcd", "abc", 1);
    cr_assert_eq(sort, 1);
}

Test(organized, cmp_alphabet09)
{
    int sort = cmp_alphabet("abc", "abc", 0);
    cr_assert_eq(sort, -1);
}

Test(organized, cmp_alphabet10)
{
    int sort = cmp_alphabet("abc", "abc", 1);
    cr_assert_eq(sort, -1);
}

Test(organized, cmp_alphabet11)
{
    int sort = cmp_alphabet("12", "13", 0);
    cr_assert_eq(sort, 1);
}
