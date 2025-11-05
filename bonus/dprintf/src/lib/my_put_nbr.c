/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** put nbr
*/

#include "my.h"
#include <unistd.h>

int my_put_nbr(int fd, int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar(fd, '-');
    }
    if (nb == -2147483648) {
        write(fd, "2147483648", 10);
        return 0;
    }
    if (nb >= 10) {
        my_put_nbr(fd, nb / 10);
    }
    my_putchar(fd, ((nb % 10) + '0'));
    return 0;
}
