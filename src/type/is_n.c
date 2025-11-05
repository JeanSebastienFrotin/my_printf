/*
** EPITECH PROJECT, 2025
** is_n
** File description:
** my_printf
*/

#include "../../include/printf.h"

void is_n(va_list arg, int *count, UNUSED format_t *option)
{
    int *n = va_arg(arg, int *);

    (*n) = (*count);
    return;
}
