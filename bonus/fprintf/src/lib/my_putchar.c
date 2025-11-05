/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** mini_dprintf
*/

#include "my.h"

int my_putchar(FILE *stream, char c)
{
    return fwrite(&c, 1, 1, stream);
}
