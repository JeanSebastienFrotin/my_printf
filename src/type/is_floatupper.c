/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** is_floatupper.c
*/
#include "../../include/printf.h"

void is_floatupper(va_list arg, int *count, format_t *option)
{
    double mydouble = 0;

    mydouble = va_arg(arg, double);
    handle_flag_float(mydouble, count, option);
    return;
}
