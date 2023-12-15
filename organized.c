/*
** EPITECH PROJECT, 2023
** organized
** File description:
** organized
*/

#include <stddef.h>
#include <stdlib.h>
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
    int return_value = 0;
    material *mat = NULL;
    material *tmp = NULL;

    return_value = workshop_shell(&mat);
    while (mat != NULL) {
        tmp = mat;
        mat = mat->next;
        free(tmp->name);
        free(tmp);
    }
    return return_value;
}
