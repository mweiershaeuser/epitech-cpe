/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hash
*/

int hash(char *key, int len)
{
    unsigned long long int hash = 5381;
    int i = 0;

    (void) len;
    while (key[i] != '\0') {
        hash = hash * 33 + key[i];
        i++;
    }
    return hash % 2147483647;
}
