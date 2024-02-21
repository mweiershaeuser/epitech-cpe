/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** Copies n characters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int length = 0;
    int i = 0;

    while (src[length] != '\0') {
        length++;
    }
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > length) {
        dest[i] = '\0';
    }
    return dest;
}
