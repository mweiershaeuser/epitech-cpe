/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Header for libmy library.
*/

#ifndef LIBMY
    #define LIBMY
int mini_printf(const char *format, ...);
void my_put_error(char *msg);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
#endif
