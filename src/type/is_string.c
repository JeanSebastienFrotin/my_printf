/*
** EPITECH PROJECT, 2025
** is_string.c
** File description:
** my_printf
*/

#include "../../include/printf.h"

void is_string(va_list arg, int *count, format_t *option)
{
    char *my_str = va_arg(arg, char *);

    handle_flag_char(my_str, count, option);
    return;
}
