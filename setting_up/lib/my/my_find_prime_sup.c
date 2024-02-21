/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** Finding the next biggest prime number.
*/

int is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    int prime = nb;
    int primeFound = 0;

    while (!primeFound) {
        primeFound = is_prime(prime);
        prime++;
    }
    return prime - 1;
}
