/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** my_putfloat.c
*/
#include "../../include/printf.h"

void my_putfloat(double num, int *count, int len_dec)
{
    int number = (int) num;
    int decimal = 0;

    if (num < 0) {
        num = -num;
    }
    if (len_dec == 0)
        len_dec = 6;
    number = (int) num;
    my_put_nbr(number, count);
    (*count) += my_putchar('.');
    for (int i = 0; i < len_dec; i++) {
        num -= (int) num;
        num *= 10;
        decimal = (int) num;
        (*count) += my_putchar('0' + decimal);
    }
}
