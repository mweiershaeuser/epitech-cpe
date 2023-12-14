/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** my_getposnbr
*/

int my_getposnbr(char const *str)
{
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
        result += str[i] - '0';
        if (str[i + 1] != '\0') {
            result *= 10;
        }
        i++;
    }
    return result;
}
