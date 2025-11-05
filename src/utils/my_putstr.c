/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** write str
*/

#include "../../include/printf.h"

int my_putstr(char const *str, int *count)
{
    for (int i = 0; str[i] != '\0'; i++) {
        (*count) += my_putchar(str[i]);
    }
    return 0;
}
