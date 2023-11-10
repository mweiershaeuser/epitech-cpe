#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../setting_up_bs.h"

Test(setting_up_bs, array_1_1, .init = cr_redirect_stdout)
{
    char arr[5] = {'a', 'b', 'c', 'd', '\0'};
    array_1d_print_chars(arr);
    cr_assert_stdout_eq_str("a\nb\nc\nd\n");
}

Test(setting_up_bs, array_2_1, .init = cr_redirect_stdout)
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    array_1d_print_ints(arr, 5);
    cr_assert_stdout_eq_str("1\n2\n3\n4\n5\n");
}

Test(setting_up_bs, array_3_1)
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int sum = array_1d_sum(arr, 5);
    cr_assert_eq(sum, 15);
}