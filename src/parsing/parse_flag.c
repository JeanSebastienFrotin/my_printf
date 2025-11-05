/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** parse_flag.c
*/

#include "../../include/printf.h"

static int check_flag(char c)
{
    char *flag = "-+ #0";

    for (int i = 0; flag[i] != '\0'; i++) {
        if (c == flag[i]) {
            return 1;
        }
    }
    return 0;
}

static int is_valid(char c, format_t *option)
{
    for (int i = 0; option->flags[i] != '\0'; i++) {
        if (option->flags[i] == c)
            return 1;
    }
    return 0;
}

int parse_flag(const char *format, int *i, format_t *option)
{
    int j = 0;

    while (format[*i] != '\0' && check_flag(format[*i]) == 1) {
        if (is_valid(format[*i], option) != 1) {
            option->flags[j] = format[*i];
            j++;
        }
        (*i)++;
    }
    return 0;
}
