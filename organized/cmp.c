/*
** EPITECH PROJECT, 2023
** organized
** File description:
** cmp
*/

#include "include/organized.h"

int cmp_numeric(int a, int b, int re)
{
    if (a == b)
        return -1;
    if (!re) {
        return a < b;
    } else {
        return a > b;
    }
}

int cmp_alphabet(const char *a, const char *b, int re)
{
    int i = 0;
    int cmp;

    while (a[i] != '\0' && b[i] != '\0') {
        cmp = cmp_numeric(a[i], b[i], re);
        if (cmp != -1)
            return cmp;
        i++;
    }
    if (a[i] == b[i])
        return -1;
    if ((!re && a[i] != '\0') || (re && b[i] != '\0'))
        return 0;
    return 1;
}
