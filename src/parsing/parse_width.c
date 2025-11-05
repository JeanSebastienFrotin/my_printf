/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** parse_width.c
*/

#include "../../include/printf.h"

static int is_nbr(char c)
{
    if (c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int parse_width(const char *format, int *i, format_t *option)
{
    long long nb = 0;

    while (format[*i] != '\0' && is_nbr(format[*i])) {
        nb = nb * 10 + (format[*i] - '0');
        (*i)++;
    }
    if (nb < 0 || nb > INT_MAX)
        nb = 0;
    option->width = nb;
    return 0;
}
