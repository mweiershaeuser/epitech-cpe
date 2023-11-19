#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/setting_up.h"

static char *get_solved(char const *filepath, int size)
{
    char *solved;
    int fd = open(filepath, O_RDONLY);

    solved = malloc(sizeof(char) * size + 1);
    read(fd, solved, size);
    solved[size] = '\0';
    close(fd);
    return solved;
}

Test(setting_up, intermediate_map_34_137_empty, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_34_137_empty.txt", 137 * 35);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_34_137_empty.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_34_137_filled, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_34_137_filled.txt", 137 * 35);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_34_137_filled.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}
