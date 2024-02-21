/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** Lightweight verison of the printf function
*/

#include <stdarg.h>
#include "../../include/my.h"

static int count_digits(int n)
{
    int sum = 0;
    int n_rest;

    n_rest = n / 10;
    if (n_rest != 0) {
        sum = count_digits(n_rest);
    }
    return sum + 1;
}

static int count_integer(int n)
{
    int sum = 0;

    if (n < 0) {
        sum++;
        n = n * -1;
    }
    return sum + count_digits(n);
}

static int handle_integer(int n)
{
    my_put_nbr(n);
    return count_integer(n);
}

static int handle_string(char *s)
{
    my_putstr(s);
    return my_strlen(s);
}

static int handle_flag(char flag, va_list *params)
{
    switch (flag) {
    case 'd':
    case 'i':
        return handle_integer(va_arg(*params, int));
    case 'c':
        my_putchar(va_arg(*params, int));
        return 1;
    case 's':
        return handle_string(va_arg(*params, char *));
    case '%':
        my_putchar(flag);
        return 1;
    default:
        return -1;
    }
}

int mini_printf(const char *format, ...)
{
    va_list params;
    int sum = 0;
    int tmp = 0;

    va_start(params, format);
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            tmp = handle_flag(*format, &params);
            sum += tmp;
        } else {
            my_putchar(*format);
            sum++;
        }
        if (tmp < 0)
            return -1;
        format++;
    }
    va_end(params);
    return sum;
}
