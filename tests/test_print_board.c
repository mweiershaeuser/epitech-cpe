#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "../include/setting_up.h"

Test(setting_up, print_board, .init = cr_redirect_stdout)
{
    board *b;

    b = malloc(sizeof(board));
    b->map = malloc(sizeof(char *) * 3);
    b->height = 3;
    b->width = 4;
    b->map[0] = ".o..";
    b->map[1] = ".o..";
    b->map[2] = ".o..";
    print_board(b);
    cr_assert_stdout_eq_str(".o..\n.o..\n.o..\n");
    free(b->map);
    free(b);
}
