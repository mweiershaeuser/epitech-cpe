/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** main
*/

#include "include/setting_up.h"

int main(int argc, char **argv)
{
    if (argc <= 1 || argc > 3) {
        put_error("Incorrect Arguments!");
        return 84;
    }
    return 0;
}
