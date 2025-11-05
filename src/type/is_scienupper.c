/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** is_scienupper.c
*/
#include "../../include/printf.h"

void print_exponent_upper(int exponent, int *count)
{
    (*count) += my_putchar('E');
    if (exponent >= 0) {
        (*count) += my_putchar('+');
    } else {
        (*count) += my_putchar('-');
        exponent = -exponent;
    }
    if (exponent < 10 && exponent >= 0)
        (*count) += my_putchar('0');
    my_put_nbr(exponent, count);
}

void is_scienupper(va_list arg, int *count, UNUSED format_t *option)
{
    int exponent = 0;
    double num = va_arg(arg, double);

    if (num < 0) {
        (*count) += my_putchar('-');
        num = -num;
    }
    exponent = get_exponent(&num);
    print_num(num, count);
    print_exponent_upper(exponent, count);
}
