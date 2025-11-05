/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** is_octal.c
*/
#include "../../include/printf.h"

static int check_size(int nb)
{
    int count = 0;

    if (nb < 0)
        nb = -nb;
    for (; nb != 0; nb /= 10) {
        count++;
    }
    return count;
}

static void put_space(int size, int *count)
{
    if (size < 0)
        return;
    for (int i = 0; i < size; i++) {
        (*count) += my_putchar(' ');
    }
    return;
}

void is_octal(va_list arg, int *count, UNUSED format_t *option)
{
    int size = 0;
    int nb = va_arg(arg, int);
    flag_t *all_flag = malloc(sizeof(flag_t));

    verify_flag(all_flag, option);
    size = check_size(nb);
    if (option->width >= size) {
        if (all_flag->minus == 0 && option->width > 0)
            put_space(option->width + 1 - size, count);
        if (all_flag->minus == 1) {
            my_putnbr_base(nb, "01234567", count);
            put_space(option->width + 1 - size, count);
            return;
        }
    }
    my_putnbr_base(nb, "01234567", count);
    return;
}
