/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** parse_format.c
*/

#include "../../include/printf.h"

int parse_format(const char *format, int *i, format_t *option)
{
    parse_flag(format, i, option);
    parse_width(format, i, option);
    parse_precision(format, i, option);
    parse_length(format, i, option);
    parse_specifier(format, i, option);
    return 0;
}
