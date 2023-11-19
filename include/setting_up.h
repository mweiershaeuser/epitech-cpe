/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Header for Setting Up
*/

#ifndef SETTING_UP_H
    #define SETTING_UP_H
typedef struct board {
    char **map;
    int width;
    int height;
} board;
typedef struct square {
    int x_pos;
    int y_pos;
    int size;
} square;
void put_error(char *msg);
int my_getposnbr(char const *str);
char *handle_input(int argc, char **argv);
board *convert_str_to_board(char *str);
square *get_largest_square(board *b);
void put_square(board *b, square *s);
void print_board(board *b);
#endif
