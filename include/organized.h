/*
** EPITECH PROJECT, 2023
** organized
** File description:
** Header for organized
*/

#ifndef ORGANIZED_H
    #define ORGANIZED_H
    #define TYPES_SIZE 5
    #define SORT_TAGS_SIZE 3

typedef enum type {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE
} type;

extern const char *TYPES[];

typedef struct material {
    int id;
    type type;
    char *name;
    struct material *next;
} material;

extern const char *SORT_TAGS[];
extern const char *SORT_RE_FLAG;

int organized(void);
void put_error(char *msg);
int cmp_numeric(int a, int b, int re);
int cmp_alphabet(char *a, char *b, int re);
#endif
