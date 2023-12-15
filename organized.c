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

const char *SORT_TAGS[] = {
    "TYPE",
    "NAME",
    "ID"
};
const char *SORT_RE_FLAG = "-r";

int organized(void)
{
    material *material = NULL;

    return workshop_shell(&material);
}
