/*
** EPITECH PROJECT, 2025
** is_pct
** File description:
** mini_printf
*/

#include "my.h"

int is_pct(FILE *stream, UNUSED va_list arg)
{
    my_putchar(stream, '%');
    return 0;
}
