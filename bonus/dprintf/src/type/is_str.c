/*
** EPITECH PROJECT, 2025
** is_str
** File description:
** mini_printf
*/

#include "my.h"

int is_str(int fd, va_list arg)
{
    char *str = va_arg(arg, char *);

    my_putstr(fd, str);
    return 0;
}
