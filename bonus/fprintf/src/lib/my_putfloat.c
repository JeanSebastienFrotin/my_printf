/*
** EPITECH PROJECT, 2025
** my_putfloat
** File description:
** mini_dprintf
*/

#include "my.h"

int my_putfloat(FILE *stream, double fl, int precision)
{
    if (fl < 0) {
        fl = -fl;
        my_putchar(stream, '-');
    }
    my_put_nbr(stream, (int)fl);
    my_putchar(stream, '.');
    for (int i = 0; i < precision; i++) {
        fl -= (int)fl;
        fl *= 10;
        my_put_nbr(stream, (int)fl);
    }
    return 0;
}
