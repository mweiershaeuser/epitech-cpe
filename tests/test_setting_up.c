#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(setting_up, wrong_file_name, .init = cr_redirect_stderr)
{
    char *argv[2] = { "setting_up", "../tests/no_such_file.txt" };
    int ret = setting_up(2, argv);
    cr_assert_eq(ret, 84);
}

Test(setting_up, too_few_arguments, .init = cr_redirect_stderr)
{
    char *argv[1] = { "setting_up" };
    int ret = setting_up(1, argv);
    cr_assert_eq(ret, 84);
}

Test(setting_up, too_many_arguments, .init = cr_redirect_stderr)
{
    char *argv[4] = { "setting_up", "4", ".o", "" };
    int ret = setting_up(1, argv);
    cr_assert_eq(ret, 84);
}
