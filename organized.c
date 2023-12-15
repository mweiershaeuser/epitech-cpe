/*
** EPITECH PROJECT, 2023
** organized
** File description:
** organized
*/

#include <stddef.h>
#include "include/shell.h"
#include "include/organized.h"

const char *TYPES[] = {
    "ACTUATOR",
    "DEVICE",
    "PROCESSOR",
    "SENSOR",
    "WIRE"
};

int organized(void)
{
    material *material = NULL;

    return workshop_shell(&material);
}
