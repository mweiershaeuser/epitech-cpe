/*
** EPITECH PROJECT, 2023
** setting_up_bs
** File description:
** Header for the Setting Up Bootstrap
*/

#ifndef SETTING_UP_BS_H
    #define SETTING_UP_BS_H
int fs_open_file(char const *filepath);
void fs_understand_return_of_read(int fd, char *buffer, int size);
void fs_cat_500_bytes(char const *filepath);
void fs_cat_x_bytes(char const *filepath, int x);
void fs_print_first_line(char const *filepath);
int fs_get_number_from_first_line(char const *filepath);
void array_1d_print_chars(char const *arr);
void array_1d_print_ints(int const *arr, int size);
int array_1d_sum(int const *arr, int size);
int array_2d_sum(int const **arr, int nb_rows, int nb_cols);
int array_2d_how_many(int const **arr, int nb_rows, int nb_cols, int number);
char *mem_alloc(char const *a, char const *b);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);
#endif
