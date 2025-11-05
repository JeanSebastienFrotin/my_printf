/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** parse_length.c
*/

#include "../../include/printf.h"

static int check_length(char c)
{
    char *length = "hljztL";

    for (int i = 0; length[i] != '\0'; i++) {
        if (c == length[i]) {
            return 1;
        }
    }
    return 0;
}

static int is_valid(format_t *option)
{
    char *length = "hljztL";

    if (option->length[0] == 'l' || option->length[0] == 'h')
        return 1;
    for (int i = 0; length[i] != '\0'; i++) {
        if (option->length[0] == length[i]) {
            return 0;
        }
    }
    return 1;
}

int parse_length(const char *format, int *i, format_t *option)
{
    int j = 0;

    while (format[*i] != '\0' && check_length(format[*i]) == 1 && j < 2) {
        if (is_valid(option) == 1) {
            option->length[j] = format[*i];
            j++;
        }
        (*i)++;
    }
    option->length[j] = '\0';
    return 0;
}
