/*
** EPITECH PROJECT, 2025
** mini_dprintf
** File description:
** mini_dprintf
*/

#include "my.h"
#include "tab.h"
#include <stdlib.h>

static int check_type(int fd, char c, va_list arg)
{
    for (int i = 0; tab_s[i].specifier != '\0'; i++) {
        if (c == tab_s[i].specifier)
            tab_s[i].func(fd, arg);
    }
    return 0;
}

int mini_dprintf(int fd, const char *format, ...)
{
    va_list arg;

    if (fd != 0 || fd != 1 || fd != 2)
        return 84;
    va_start(arg, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == '\0')
            return 0;
        if (format[i] == '%') {
            i++;
            check_type(fd, format[i], arg);
        } else {
            my_putchar(fd, str[i]);
        }
    }
    va_end(arg);
    return 0;
}
