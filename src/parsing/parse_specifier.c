/*
** EPITECH PROJECT, 2025
** parse_format.c
** File description:
** my_printf
*/


#include "../../include/printf.h"

static int check_specifier(char c)
{
    const char *specifier = "diuoxXfFeEgGaAcspn%";

    for (int i = 0; specifier[i] != '\0'; i++) {
        if (c == specifier[i])
            return 1;
    }
    return 0;
}

int parse_specifier(const char *format, int *i, format_t *option)
{
    for (; format[*i] != '\0'; (*i)++) {
        if (check_specifier(format[*i]) == 1) {
            option->specifier = format[*i];
            break;
        }
    }
    return 0;
}
