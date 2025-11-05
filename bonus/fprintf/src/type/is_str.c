/*
** EPITECH PROJECT, 2025
** is_str
** File description:
** mini_printf
*/

#include "my.h"

int is_str(FILE *stream, va_list arg)
{
    char *str = va_arg(arg, char *);

    my_putstr(stream, str);
    return 0;
}
