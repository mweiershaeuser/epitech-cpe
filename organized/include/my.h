/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Header for libmy library.
*/

#ifndef LIBMY
    #define LIBMY
int my_getposnbr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int mini_printf(const char *format, ...);
#endif
