/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** put nbr
*/

#include "my.h"
#include <unistd.h>

int my_put_nbr(FILE *stream, int nb)
{
    char buffer[10] = "2147483648";

    if (nb < 0) {
        nb = -nb;
        my_putchar(stream, '-');
    }
    if (nb == -2147483648) {
        fwrite(buffer, 1, 10, stream);
        return 0;
    }
    if (nb >= 10) {
        my_put_nbr(stream, nb / 10);
    }
    my_putchar(stream, ((nb % 10) + '0'));
    return 0;
}
