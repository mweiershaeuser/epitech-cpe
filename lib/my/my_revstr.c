/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** Reverse a string.
*/

static int count_chars(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

static void swap_chars(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int length;

    length = count_chars(str);
    for (int i = 0; i < length / 2; i++) {
        swap_chars(&str[i], &str[length - 1 - i]);
    }
    return str;
}
