/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** handle_flag.c
*/
#include "../../include/printf.h"

void init_flag(flag_t *all_flag)
{
    all_flag->minus = 0;
    all_flag->plus = 0;
    all_flag->space = 0;
    all_flag->hashtag = 0;
    all_flag->zero = 0;
    return;
}

void verify_flag(flag_t *all_flag, format_t *option)
{
    init_flag(all_flag);
    for (int i = 0; option->flags[i] != '\0'; i++) {
        if (option->flags[i] == '-')
            all_flag->minus = 1;
        if (option->flags[i] == '+')
            all_flag->plus = 1;
        if (option->flags[i] == ' ')
            all_flag->space = 1;
        if (option->flags[i] == '#')
            all_flag->hashtag = 1;
        if (option->flags[i] == '0')
            all_flag->zero = 1;
    }
    return;
}

static int get_new_width(long long myint)
{
    int count = 0;

    if (myint == 0)
        return 1;
    if (myint < 0)
        count++;
    while (myint != 0) {
        myint /= 10;
        count++;
    }
    return count;
}

static int check_padding_zero(long long myint, int *count,
    format_t *option, flag_t *all_flag)
{
    int new_width = 0;
    int is_neg = 0;

    if (all_flag->zero == 1 && all_flag->minus == 0 &&
        option->precision == 0) {
        new_width = get_new_width(myint);
        if (myint < 0) {
            myint = -myint;
            is_neg = 1;
            (*count) += my_putchar('-');
        }
        for (int i = 0; i < (option->width - new_width); i++)
            (*count) += my_putchar('0');
    }
    if (all_flag->zero == 0) {
        new_width = get_new_width(myint);
        for (int i = 0; i < (option->width - new_width); i++)
            (*count) += my_putchar(' ');
    }
    return is_neg;
}

static int check_padding(long long myint, int *count,
    format_t *option, flag_t *all_flag)
{
    int new_width = 0;

    if (all_flag->minus == 1) {
        new_width = get_new_width(myint);
        if (all_flag->plus == 1 && myint > 0) {
            (*count) += my_putchar('+');
            new_width += 1;
        }
        my_put_nbr(myint, count);
        for (int i = 0; i < (option->width - new_width); i++) {
            (*count) += my_putchar(' ');
        }
        handle_precision(myint, count, option);
        return 1;
    }
    return 0;
}

static void put_plus(flag_t *all_flag, long long myint, int *count)
{
    if (all_flag->plus == 1) {
        if (myint > 0)
            (*count) += my_putchar('+');
    }
}

void handle_flag_int(long long myint, int *count, format_t *option)
{
    flag_t *all_flag = malloc(sizeof(flag_t));

    verify_flag(all_flag, option);
    if (check_padding(myint, count, option, all_flag))
        return;
    put_plus(all_flag, myint, count);
    if (all_flag->space == 1 && all_flag->plus == 0) {
        if (myint > 0)
            (*count) += my_putchar(' ');
    }
    if (check_padding_zero(myint, count, option, all_flag))
        myint = -myint;
    if (myint < 0 && option->precision > 0) {
        myint = -myint;
        (*count) += my_putchar('-');
    }
    handle_precision(myint, count, option);
    my_put_nbr(myint, count);
    return;
}
