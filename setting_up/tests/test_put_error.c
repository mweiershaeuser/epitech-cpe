#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(setting_up, test_one, .init = cr_redirect_stderr)
{
    put_error("Des choses horribles se sont passés!\n");
    cr_assert_stderr_eq_str("Des choses horribles se sont passés!\n");
}
