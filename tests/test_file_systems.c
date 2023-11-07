#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../setting_up_bs.h"

Test(setting_up_bs, file_systems1, .init = cr_redirect_stdout)
{
    int res = fs_open_file("../tests/test.txt");
    cr_assert_stdout_eq_str("SUCCESS\n");
}

Test(setting_up_bs, file_systems2, .init = cr_redirect_stdout)
{
    int res = fs_open_file("test_failure.txt");
    cr_assert_stdout_eq_str("FAILURE\n");
}
