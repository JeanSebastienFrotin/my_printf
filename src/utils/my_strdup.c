/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** my_strdup.c
*/
#include "../../include/printf.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *new_src = malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        new_src[i] = src[i];
    }
    new_src[len] = '\0';
    return new_src;
}
