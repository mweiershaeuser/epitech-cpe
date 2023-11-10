#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include "../setting_up_bs.h"

Test(setting_up_bs, file_systems_1_1, .init = cr_redirect_stdout)
{
    int res = fs_open_file("../tests/test.txt");
    cr_assert_stdout_eq_str("SUCCESS\n");
}

Test(setting_up_bs, file_systems_1_2, .init = cr_redirect_stdout)
{
    int res = fs_open_file("test_failure.txt");
    cr_assert_stdout_eq_str("FAILURE\n");
}

Test(setting_up_bs, file_systems_2_1, .init = cr_redirect_stdout)
{
    char buffer[5] = "";
    fs_understand_return_of_read(-5, buffer, 5);
    cr_assert_stdout_eq_str("read failed\n");
}

Test(setting_up_bs, file_systems_2_2, .init = cr_redirect_stdout)
{
    char buffer[13] = "";
    int fd = open("../tests/test.txt", O_RDONLY);
    read(fd, buffer, 13);
    fs_understand_return_of_read(fd, buffer, 13);
    cr_assert_stdout_eq_str("read has nothing more to read\n");
}

Test(setting_up_bs, file_systems_2_3, .init = cr_redirect_stdout)
{
    char buffer[20] = "";
    int fd = open("../tests/test.txt", O_RDONLY);
    fs_understand_return_of_read(fd, buffer, 20);
    cr_assert_stdout_eq_str("read didn’t complete the entire buffer\n");
}

Test(setting_up_bs, file_systems_2_4, .init = cr_redirect_stdout)
{
    char buffer[13] = "";
    int fd = open("../tests/test.txt", O_RDONLY);
    fs_understand_return_of_read(fd, buffer, 13);
    cr_assert_stdout_eq_str("read completed the entire buffer\n");
}