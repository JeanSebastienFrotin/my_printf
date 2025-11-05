/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** parse_precision.c
*/

#include "../../include/printf.h"

static int is_nbr(char c)
{
    if (c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

static int check_precision(const char *format, int *i, format_t *option)
{
    if (format[*i] == '.' && format[*i + 1] == '*') {
        option->precision_ast = 1;
        (*i) += 2;
        return 1;
    }
    if (format[*i] == '.' &&
        !(format[*i + 1] == '*' || is_nbr(format[*i + 1]))) {
        option->precision_dot = 1;
        (*i)++;
        return 1;
    }
    return 0;
}

int parse_precision(const char *format, int *i, format_t *option)
{
    long long nb = 0;

    if (check_precision(format, i, option) == 1)
        return 0;
    if (format[*i] == '.') {
        (*i)++;
        while (format[*i] != '\0' && is_nbr(format[*i])) {
            nb = nb * 10 + (format[*i] - '0');
            (*i)++;
        }
    }
    if (nb < 0 || nb > INT_MAX)
        nb = 0;
    option->precision = nb;
    return 0;
}
