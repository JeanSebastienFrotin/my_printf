/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** is_short.c
*/
#include "../../include/printf.h"

static void call_flag_e(double num, int exponent, int *count)
{
    print_num(num, count);
    print_exponent(exponent, count);
}

void is_short(va_list arg, int *count, format_t *option)
{
    int precision = option->precision;
    int exponent = 0;
    double num = va_arg(arg, double);
    double num2 = num;

    if (precision == 0)
        precision = 6;
    if (num < 0)
        num = -num;
    exponent = get_exponent(&num2);
    if (exponent < -4 || exponent >= precision) {
        call_flag_e(num2, exponent, count);
        return;
    }
    handle_flag_float(num, count, option);
    return;
}
