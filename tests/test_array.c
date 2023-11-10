#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../setting_up_bs.h"

Test(setting_up_bs, array_1_1, .init = cr_redirect_stdout)
{
    char arr[5] = {'a', 'b', 'c', 'd', '\0'};
    array_1d_print_chars(arr);
    cr_assert_stdout_eq_str("a\nb\nc\nd\n");
}