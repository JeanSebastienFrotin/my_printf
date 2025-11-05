/*
** EPITECH PROJECT, 2025
** my_revstr.c
** File description:
** my_printf
*/

#include "../../include/printf.h"

static void my_swap_char(char *a, char *b)
{
    char temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;

    for (; i < j; i++) {
        my_swap_char(&str[i], &str[j]);
        j--;
    }
    return str;
}
