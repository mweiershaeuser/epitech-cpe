/*
** EPITECH PROJECT, 2023
** mem_alloc
** File description:
** mem_alloc
*/

#include <stdlib.h>
#include "my.h"

char *mem_alloc(char const *a, char const *b)
{
    int len_a = my_strlen(a);
    int len_b = my_strlen(b);
    char *res;

    res = malloc(sizeof(char) * (len_a + len_b + 1));
    my_strcpy(res, a);
    my_strcat(res, b);
    return res;
}
