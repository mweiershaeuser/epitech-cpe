#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(setting_up, test_one, .init = cr_redirect_stdout)
{
    setting_up();
    cr_assert_stdout_eq_str("Hello ");
}
