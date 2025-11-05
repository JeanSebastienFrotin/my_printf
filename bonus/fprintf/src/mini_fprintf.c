/*
** EPITECH PROJECT, 2025
** mini_fprintf
** File description:
** mini_fprintf
*/

#include "my.h"
#include "tab.h"
#include <stdio.h>
#include <fcntl.h>

static int check_type(FILE *stream, char c, va_list arg)
{
    for (int i = 0; tab_s[i].specifier != '\0'; i++) {
        if (c == tab_s[i].specifier)
            tab_s[i].func(stream, arg);
    }
    return 0;
}

int mini_fprintf(FILE *stream, const char *format, ...)
{
    va_list arg;

    va_start(arg, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == '\0')
            return 0;
        if (format[i] == '%') {
            i++;
            check_type(stream, format[i], arg);
        } else {
            my_putchar(stream, format[i]);
        }
    }
    va_end(arg);
    return 0;
}
