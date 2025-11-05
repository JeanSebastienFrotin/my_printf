/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** handle_precision.c
*/
#include "../../include/printf.h"

static int get_precision(long long myint, format_t *option)
{
    int count = 0;

    if (myint == 0 && option->precision == 0) {
        return 0;
    }
    if (myint < 0) {
        myint = -myint;
    }
    while (myint * 0.1 > 0) {
        myint *= 0.1;
        count += 1;
    }
    return count;
}

void handle_precision(long long myint, int *count, format_t *option)
{
    int new_precision = get_precision(myint, option);

    if (option->precision > 0 && option->precision > new_precision) {
        for (int i = 0; i < (option->precision - new_precision); i++) {
            count += my_putchar('0');
        }
    }
}
