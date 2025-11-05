/*
** EPITECH PROJECT, 2025
** is_flt
** File description:
** mini_printf
*/

#include "my.h"

int is_flt(FILE *stream, va_list arg)
{
    double fl = va_arg(arg, double);

    my_putfloat(stream, fl, 6);
    return 0;
}
