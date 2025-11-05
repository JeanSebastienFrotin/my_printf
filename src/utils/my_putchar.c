/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** put char
*/

#include "../../include/printf.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}
