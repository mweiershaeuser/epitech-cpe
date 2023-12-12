/*
** EPITECH PROJECT, 2023
** organized
** File description:
** Header for organized
*/

#ifndef ORGANIZED_H
    #define ORGANIZED_H
    #define TYPES_SIZE 5

typedef enum type {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE
} type;

static const char *TYPES[] = {
    "ACTUATOR",
    "DEVICE",
    "PROCESSOR",
    "SENSOR",
    "WIRE"
};

typedef struct material {
    int id;
    type type;
    char *name;
    struct material *next;
} material;
int organized(void);
#endif
