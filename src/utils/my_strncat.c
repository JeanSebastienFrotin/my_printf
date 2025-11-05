/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** my_strncat.c
*/
#include "../../include/printf.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int len = 0;
    int i = 0;

    while (dest[len] != '\0')
        len++;
    while (i < n && src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return dest;
}
