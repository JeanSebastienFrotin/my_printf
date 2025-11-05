/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** put nbr
*/

#include "../../include/printf.h"

int my_put_nbr(int nb, int *count)
{
    if (nb < 0) {
        nb = -nb;
        (*count) += my_putchar('-');
    }
    if (nb == -2147483648) {
        (*count) += write(1, "2147483648", 10);
        return 0;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10, count);
    }
    (*count) += my_putchar((nb % 10) + '0');
    return 0;
}
