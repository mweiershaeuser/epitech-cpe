#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../bootstrap.h"
#include "../organized_bs.h"

Test(organized_bs, print_typed_value_int, .init = cr_redirect_stdout)
{
    int nb = -76;
    print_typed_value(&nb, INTEGER);
    cr_assert_stdout_eq_str("-76\n");
}

Test(organized_bs, print_typed_value_char, .init = cr_redirect_stdout)
{
    char c = 'a';
    print_typed_value(&c, CHAR);
    cr_assert_stdout_eq_str("a\n");
}

Test(organized_bs, print_typed_value_string, .init = cr_redirect_stdout)
{
    char *str = "Hello World!";
    print_typed_value(str, STRING);
    cr_assert_stdout_eq_str("Hello World!\n");
}

Test(organized_bs, print_typed_value_player, .init = cr_redirect_stdout)
{
    player_t p = { "Hoppy", 98 };
    print_typed_value(&p, PLAYER);
    cr_assert_stdout_eq_str("Hoppy: lvl.98\n");
}
