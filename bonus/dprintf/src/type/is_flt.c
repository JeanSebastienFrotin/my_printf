/*
** EPITECH PROJECT, 2025
** is_flt
** File description:
** mini_printf
*/

#include "my.h"

int is_flt(int fd, va_list arg)
{
    double fl = va_arg(arg, double);

    my_putfloat(fd, fl, 6);
    return 0;
}
