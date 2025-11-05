/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** handle_flag_float.c
*/
#include "../../include/printf.h"

static int nb_len(int nb)
{
    int len = 0;

    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return len;
}

static int len_of_float(float nbr, int precision, flag_t *all_flag)
{
    int power = 1;
    int decimal = 0;
    int int_part = (int)nbr;
    int len = nb_len(int_part);

    if (precision == 0)
        precision = 6;
    for (int i = 0; i < precision; i++) {
        power *= 10;
    }
    decimal = power * (nbr - int_part);
    len += nb_len(decimal);
    if (decimal != 0) {
        len += 1;
    }
    if (all_flag->plus)
        len += 1;
    if (all_flag->space)
        len += 1;
    return len;
}

int check_neg(double *mynbr)
{
    int is_neg = 0;

    if (*mynbr < 0) {
        *mynbr = -(*mynbr);
        is_neg = 1;
    }
    return is_neg;
}

static int check_padding(double mynbr, int *count,
    format_t *option, flag_t *all_flag)
{
    int is_neg = check_neg(&mynbr);
    int len = len_of_float(mynbr, option->precision, all_flag);

    if (all_flag->minus == 1) {
        if (all_flag->plus == 1 && mynbr > 0 && is_neg == 0) {
            (*count) += my_putchar('+');
        }
        if (is_neg) {
            (*count) += my_putchar('-');
            len += 1;
        }
        my_putfloat(mynbr, count, option->precision);
        for (int i = 0; i < (option->width - len); i++) {
            (*count) += my_putchar(' ');
        }
        return 1;
    }
    return 0;
}

static void put_plus(flag_t *all_flag, double mynbr, int *count, int is_neg)
{
    if (all_flag->plus == 1 && mynbr > 0 && is_neg == 0) {
        (*count) += my_putchar('+');
    }
}

static int check_padding_zero(double mynbr, int *count,
    format_t *option, flag_t *all_flag)
{
    int is_neg = check_neg(&mynbr);
    int len = len_of_float(mynbr, option->precision, all_flag);

    if (all_flag->zero == 1 && all_flag->minus == 0) {
        if (is_neg) {
            (*count) += my_putchar('-');
            len += 1;
        }
        for (int i = 0; i < (option->width - len); i++)
            (*count) += my_putchar('0');
    }
    if (all_flag->zero == 0) {
        len = len_of_float(mynbr, option->precision, all_flag);
        for (int i = 0; i < (option->width - len); i++)
            (*count) += my_putchar(' ');
    }
    return is_neg;
}

void handle_flag_float(double mynbr, int *count, format_t *option)
{
    int is_neg = 0;
    flag_t *all_flag = malloc(sizeof(flag_t));

    verify_flag(all_flag, option);
    if (check_padding(mynbr, count, option, all_flag))
        return;
    if (all_flag->space == 1 && all_flag->plus == 0) {
        if (mynbr > 0)
            (*count) += my_putchar(' ');
    }
    is_neg = check_padding_zero(mynbr, count, option, all_flag);
    put_plus(all_flag, mynbr, count, is_neg);
    if (is_neg && all_flag->zero == 0)
        (*count) += my_putchar('-');
    my_putfloat(mynbr, count, option->precision);
    return;
}
