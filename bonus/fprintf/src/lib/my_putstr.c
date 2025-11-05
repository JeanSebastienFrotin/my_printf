/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** write str
*/

#include "my.h"

int my_putstr(FILE *stream, char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(stream, str[i]);
    }
    return 0;
}
