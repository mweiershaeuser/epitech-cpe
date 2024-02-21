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

Test(setting_up, intermediate_map_34_137_with_obstacles_25pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_34_137_with_obstacles_25pc.txt", 137 * 35);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_34_137_with_obstacles_25pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_34_137_with_obstacles_50pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_34_137_with_obstacles_50pc.txt", 137 * 35);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_34_137_with_obstacles_50pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_34_137_with_obstacles_75pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_34_137_with_obstacles_75pc.txt", 137 * 35);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_34_137_with_obstacles_75pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_97_21_empty, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_97_21_empty.txt", 21 * 98);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_97_21_empty.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_97_21_filled, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_97_21_filled.txt", 21 * 98);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_97_21_filled.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_97_21_with_obstacles_25pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_97_21_with_obstacles_25pc.txt", 21 * 98);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_97_21_with_obstacles_25pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_97_21_with_obstacles_50pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_97_21_with_obstacles_50pc.txt", 21 * 98);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_97_21_with_obstacles_50pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_97_21_with_obstacles_75pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_97_21_with_obstacles_75pc.txt", 21 * 98);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_97_21_with_obstacles_75pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_100_100, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_100_100.txt", 100 * 101);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_100_100.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}
/*
Test(setting_up, intermediate_map_187_187_empty, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_187_187_empty.txt", 187 * 188);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_187_187_empty.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_187_187_filled, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_187_187_filled.txt", 187 * 188);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_187_187_filled.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_187_187_with_obstacles_25pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_187_187_with_obstacles_25pc.txt", 187 * 188);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_187_187_with_obstacles_25pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_187_187_with_obstacles_50pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_187_187_with_obstacles_50pc.txt", 187 * 188);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_187_187_with_obstacles_50pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_187_187_with_obstacles_75pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_187_187_with_obstacles_75pc.txt", 187 * 188);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_187_187_with_obstacles_75pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_200_200, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_200_200.txt", 200 * 201);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_200_200.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_500_500, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_500_500.txt", 500 * 501);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_500_500.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_500_500_2, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_500_500_2.txt", 500 * 501);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_500_500_2.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_500_500_3, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_500_500_3.txt", 500 * 501);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_500_500_3.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_1000_1000, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_1000_1000.txt", 1000 * 1001);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_1000_1000.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_1000_1000_2, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_1000_1000_2.txt", 1000 * 1001);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_1000_1000_2.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}
*/
Test(setting_up, intermediate_map_filled_corners, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_filled_corners.txt", 50 * 51);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_filled_corners.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_empty_corners, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_filled_corners.txt", 50 * 51);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_filled_corners.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_column_with_obstacles_25pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_column_with_obstacles_25pc.txt", 100 * 2);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_column_with_obstacles_25pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_column_with_obstacles_50pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_column_with_obstacles_50pc.txt", 100 * 2);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_column_with_obstacles_50pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_column_with_obstacles_75pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_column_with_obstacles_75pc.txt", 100 * 2);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_column_with_obstacles_75pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_empty_box, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_empty_box.txt", 1 * 2);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_empty_box.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_empty_column, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_empty_column.txt", 100 * 2);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_empty_column.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_empty_line, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_empty_line.txt", 1 * 101);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_empty_line.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_filled_box, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_filled_box.txt", 1 * 2);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_filled_box.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_filled_column, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_filled_column.txt", 100 * 2);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_filled_column.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_filled_line, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_filled_line.txt", 1 * 101);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_filled_line.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_line_with_obstacles_25pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_line_with_obstacles_25pc.txt", 1 * 101);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_line_with_obstacles_25pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_line_with_obstacles_50pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_line_with_obstacles_50pc.txt", 1 * 101);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_line_with_obstacles_50pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}

Test(setting_up, intermediate_map_one_line_with_obstacles_75pc, .init = cr_redirect_stdout)
{
    char *solved = get_solved("../tests/example_files/solved/intermediate_map_one_line_with_obstacles_75pc.txt", 1 * 101);
    char *argv[2] = { "setting_up", "../tests/example_files/maps/intermediate_map_one_line_with_obstacles_75pc.txt" };
    setting_up(2, argv);
    cr_assert_stdout_eq_str(solved);
    free(solved);
}
