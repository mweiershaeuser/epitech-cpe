/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** Computes the square root of a given number,
** if it is a whole number.
*/

int my_compute_square_root(int nb)
{
    int sr;
    int counter = 0;

    for (sr = 1; counter < nb; sr++) {
        counter = sr * sr;
    }
    if (counter == nb) {
        return sr - 1;
    } else {
        return 0;
    }
}
