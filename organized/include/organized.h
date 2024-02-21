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

typedef enum sort_tag {
    TYPE,
    NAME,
    ID
} sort_tag;

extern const char *SORT_TAGS[];
extern const char *SORT_RE_FLAG;

typedef struct sort_params {
    sort_tag tag;
    int reverse;
    struct sort_params *next;
} sort_params;

int organized(void);
void put_error(char *msg);
int cmp_numeric(int a, int b, int re);
int cmp_alphabet(const char *a, const char *b, int re);
#endif
