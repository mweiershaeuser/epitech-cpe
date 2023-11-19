/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** find_square
*/

#include <stdlib.h>
#include "include/setting_up.h"

static int get_size(square *s, board *b, int radius)
{
    int return_value = 1;

    if (s->y_pos + radius >= b->height
        || s->x_pos + radius >= b->width) {
        return 0;
    }
    for (int i = s->y_pos; i <= s->y_pos + radius; i++) {
        for (int j = s->x_pos; j <= s->x_pos + radius; j++) {
            return_value = b->map[i][j] != '.' ? 0 : return_value;
        }
    }
    if (return_value == 0) {
        return 0;
    }
    return 1 + get_size(s, b, radius + 1);
}

static square *larger_square(square *s1, square *s2)
{
    if (s1->size > s2->size) {
        free(s2);
        return s1;
    }
    if (s2->size > s1->size) {
        free(s1);
        return s2;
    }
    return NULL;
}

static square *higher_square(square *s1, square *s2)
{
    if (s1->y_pos < s2->y_pos) {
        free(s2);
        return s1;
    }
    if (s2->y_pos < s1->y_pos) {
        free(s1);
        return s2;
    }
    return NULL;
}

static square *left_most_square(square *s1, square *s2)
{
    if (s1->x_pos < s2->x_pos) {
        free(s2);
        return s1;
    }
    if (s2->x_pos < s1->x_pos) {
        free(s1);
        return s2;
    }
    return NULL;
}

static square *compare_squares(square *s1, square *s2)
{
    square *largest_square;
    square *highest_square;
    square *leftest_square;

    largest_square = larger_square(s1, s2);
    if (largest_square != NULL)
        return largest_square;
    highest_square = higher_square(s1, s2);
    if (highest_square != NULL)
        return highest_square;
    leftest_square = left_most_square(s1, s2);
    if (leftest_square != NULL)
        return leftest_square;
    free(s2);
    return s1;
}

square *get_largest_square(board *b)
{
    square *largest_square;
    square *current_square;

    largest_square = malloc(sizeof(square));
    largest_square->size = -1;
    for (int i = 0; i < b->height; i++) {
        for (int j = 0; j < b->width; j++) {
            current_square = malloc(sizeof(square));
            current_square->y_pos = i;
            current_square->x_pos = j;
            current_square->size = get_size(current_square, b, 0);
            largest_square = compare_squares(current_square, largest_square);
        }
    }
    return largest_square;
}
