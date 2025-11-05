/*
** EPITECH PROJECT, 2025
** my_putnbr_base
** File description:
** my_printf
*/

#include "../../include/printf.h"

int my_putnbr_base(long long nbr, char const *base, int *count)
{
    int my_base = my_strlen(base);

    if (nbr < 0) {
        nbr = -nbr;
    }
    if (nbr >= my_base) {
        my_putnbr_base(nbr / my_base, base, count);
    }
    (*count) += my_putchar(base[(nbr % my_base)]);
    return 0;
}
