/*
** EPITECH PROJECT, 2025
** is_chr
** File description:
** mini_printf
*/

#include "my.h"
#include <stdio.h>

int is_chr(FILE *stream, va_list arg)
{
    char c = va_arg(arg, int);

    my_putchar(stream, c);
    return 0;
}
