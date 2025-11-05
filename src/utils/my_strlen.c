/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** len of string
*/

#include "../../include/printf.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
