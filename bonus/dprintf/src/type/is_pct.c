/*
** EPITECH PROJECT, 2025
** is_pct
** File description:
** mini_printf
*/

#include "my.h"

int is_pct(int fd, UNUSED va_list arg)
{
    my_putchar(fd, '%');
    return 0;
}
