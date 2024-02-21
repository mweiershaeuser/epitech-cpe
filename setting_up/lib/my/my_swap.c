/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** Swap the content of two integers.
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
