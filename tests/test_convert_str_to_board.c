#include <criterion/criterion.h>
#include "../include/setting_up.h"

Test(setting_up, convert_str_to_board)
{
    board *b = convert_str_to_board(".o..\n.o..\n.o..\n");
    cr_assert_eq(b->height, 3);
    cr_assert_eq(b->width, 4);
    cr_assert_str_eq(b->map[0], ".o..");
    cr_assert_str_eq(b->map[1], ".o..");
    cr_assert_str_eq(b->map[2], ".o..");
}
