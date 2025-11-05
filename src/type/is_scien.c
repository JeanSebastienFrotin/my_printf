/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** is_scien.c
*/
#include "../../include/printf.h"

int get_exponent(double *num)
{
    int exponent = 0;

    while (*num >= 10.0) {
        *num /= 10;
        exponent++;
    }
    while (*num < 1.0 && *num > 0) {
        *num *= 10;
        exponent--;
    }
    return exponent;
}

void print_num(double num, int *count)
{
    int integer = (int)num;
    int decimal = 0;

    my_put_nbr(integer, count);
    (*count) += my_putchar('.');
    for (int i = 0; i < 6; i++) {
        num -= (int)num;
        num *= 10;
        decimal = (int)num;
        (*count) += my_putchar('0' + decimal);
    }
}

void print_exponent(int exponent, int *count)
{
    (*count) += my_putchar('e');
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

void is_scien(va_list arg, int *count, UNUSED format_t *option)
{
    int exponent = 0;
    double num = va_arg(arg, double);

    if (num < 0) {
        (*count) += my_putchar('-');
        num = -num;
    }
    exponent = get_exponent(&num);
    print_num(num, count);
    print_exponent(exponent, count);
}
