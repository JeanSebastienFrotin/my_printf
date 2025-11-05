/*
** EPITECH PROJECT, 2025
** is_int
** File description:
** mini_printf
*/

#include "my.h"

int is_int(FILE *stream, va_list arg)
{
    int nb = va_arg(arg, int);

    my_put_nbr(stream, nb);
    return 0;
}
