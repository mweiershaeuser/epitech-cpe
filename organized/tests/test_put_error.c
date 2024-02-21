#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/organized.h"

Test(organized, put_error, .init = cr_redirect_stderr)
{
    put_error("Des choses horribles se sont passés!\n");
    cr_assert_stderr_eq_str("Des choses horribles se sont passés!\n");
}
