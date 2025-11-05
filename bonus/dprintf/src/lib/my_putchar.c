/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** mini_dprintf
*/

#include "my.h"

int my_putchar(int fd, char c)
{
    return write(fd, &c, 1);
}
