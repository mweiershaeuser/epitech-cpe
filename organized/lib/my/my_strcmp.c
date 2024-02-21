/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** my_strcmp
*/

static int compare_char(char const s1, char const s2)
{
    if (s1 > s2)
        return 1;
    if (s2 > s1)
        return -1;
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int current_char_cmp;

    while (s1[i] != '\0' && s2[i] != '\0') {
        current_char_cmp = compare_char(s1[i], s2[i]);
        if (current_char_cmp)
            return current_char_cmp;
        i++;
    }
    current_char_cmp = compare_char(s1[i], s2[i]);
    return current_char_cmp;
}
