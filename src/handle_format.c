/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** handle_format.c
*/

#include "../include/printf.h"

int char_is_in(char c)
{
    const char *specifiers = "diuoxXfFeEgGaAcspn%";

    for (int i = 0; specifiers[i] != '\0'; i++) {
        if (c == specifiers[i])
            return 1;
    }
    return 0;
}

int to_skip(char c)
{
    const char *lengths = "hljztL-+ #00123456789.*";

    for (int i = 0; lengths[i] != '\0'; i++) {
        if (c == lengths[i])
            return 1;
    }
    return 0;
}

int is_specifier(const char *format, int *i)
{
    int idx = *i + 1;

    while (format[idx] != '\0' && to_skip(format[idx]) == 1)
        idx++;
    if (char_is_in(format[idx]))
        return 1;
    return 0;
}
