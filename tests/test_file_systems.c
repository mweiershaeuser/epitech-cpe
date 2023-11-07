#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../setting_up_bs.h"

Test(setting_up_bs, file_systems1, .init = cr_redirect_stdout)
{
    cr_assert_eq(fs_open_file("tests.txt"), 0);
}
