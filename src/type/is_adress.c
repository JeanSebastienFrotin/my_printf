/*
** EPITECH PROJECT, 2025
** is_adress
** File description:
** my_printf
*/

#include "../../include/printf.h"

void is_adress(va_list arg, int *count, UNUSED format_t *option)
{
    long long adress = va_arg(arg, long long);

    if (adress == 0) {
        my_putstr("(nil)", count);
        return;
    }
    my_putstr("0x", count);
    my_putnbr_base(adress, "0123456789abcdef", count);
    return;
}
