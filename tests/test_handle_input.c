#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "../include/setting_up.h"

Test(setting_up, handle_input_error_1, .init = cr_redirect_stderr)
{
    char *argv[1] = { "setting_up" };
    char *board_str = handle_input(1, argv);
    cr_assert_eq(board_str, 0);
    cr_assert_stderr_eq_str("Incorrect Arguments!\n");
    free(board_str);
}

Test(setting_up, handle_input_error_2, .init = cr_redirect_stderr)
{
    char *argv[4] = { "setting_up", "4", "", "" };
    cr_assert_eq(handle_input(4, argv), 0);
    cr_assert_stderr_eq_str("Incorrect Arguments!\n");
}

Test(setting_up, handle_input_file)
{
    char *argv[2] = { "setting_up", "../tests/test_map.txt" };
    char *board_str = handle_input(2, argv);
    cr_assert_str_eq(board_str, ".....o...o\no....o..oo\n....o..o..\n");
    free(board_str);
}

Test(setting_up, handle_input_file_error, .init = cr_redirect_stderr)
{
    char *argv[2] = { "setting_up", "../tests/testmap.txt" };
    cr_assert_eq(handle_input(2, argv), 0);
    cr_assert_stderr_eq_str("Error opening file.\n");
}

Test(setting_up, handle_input_generator)
{
    char *argv[3] = { "setting_up", "4", "..o." };
    char *board_str = handle_input(3, argv);
    cr_assert_str_eq(board_str, "..o.\n..o.\n..o.\n..o.\n");
    free(board_str);
}
