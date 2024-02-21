/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Returns the number of characters in a string.
*/

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
