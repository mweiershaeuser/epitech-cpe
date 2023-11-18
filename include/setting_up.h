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
void put_error(char *msg);
int my_getposnbr(char const *str);
char *handle_input(int argc, char **argv);
board *convert_str_to_board(char *str);
void print_board(board *b);
#endif
