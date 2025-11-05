/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** is_float.c
*/
#include "../../include/printf.h"

void is_float(va_list arg, int *count, format_t *option)
{
    double mydouble = 0;

    mydouble = va_arg(arg, double);
    handle_flag_float(mydouble, count, option);
    return;
}
