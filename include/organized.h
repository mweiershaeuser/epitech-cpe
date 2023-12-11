/*
** EPITECH PROJECT, 2023
** organized
** File description:
** Header for organized
*/

#ifndef ORGANIZED_H
    #define ORGANIZED_H
typedef enum type {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE
} type;
/*
static const char *TYPES[] = {
    "ACTUATOR",
    "DEVICE",
    "PROCESSOR",
    "SENSOR",
    "WIRE"
};
*/
typedef struct material {
    int id;
    type type;
    char *name;
} material;
typedef struct node {
    void *data;
    struct node *next;
} node;
int organized(void);
#endif
