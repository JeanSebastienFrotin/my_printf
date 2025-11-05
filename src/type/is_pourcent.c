/*
** EPITECH PROJECT, 2025
** is_pourcent.c
** File description:
** my_printf
*/

#include "../../include/printf.h"

void is_pourcent(UNUSED va_list arg, int *count, UNUSED format_t *option)
{
    (*count) += my_putchar('%');
    return;
}
