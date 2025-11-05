/*
** EPITECH PROJECT, 2025
** is_int
** File description:
** mini_printf
*/

#include "my.h"

int is_int(int fd, va_list arg)
{
    int nb = va_arg(arg, int);

    my_put_nbr(fd, nb);
    return 0;
}
