/*
** EPITECH PROJECT, 2025
** is_int.c
** File description:
** my_printf
*/

#include "../../include/printf.h"

void is_int(va_list arg, int *count, format_t *option)
{
    int myint = 0;

    myint = va_arg(arg, int);
    handle_flag_int(myint, count, option);
    return;
}
