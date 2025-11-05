/*
** EPITECH PROJECT, 2025
** is_char.c
** File description:
** my_printf
*/

#include "../../include/printf.h"

void is_char(va_list arg, int *count, format_t *option)
{
    flag_t *all_flag = malloc(sizeof(flag_t));
    char c = va_arg(arg, int);

    verify_flag(all_flag, option);
    if (all_flag->minus == 1) {
        (*count) += my_putchar(c);
        for (int i = 0; i != (option->width - 1); i++) {
            (*count) += my_putchar(' ');
        }
        free(all_flag);
        return;
    }
    (*count) += my_putchar(c);
    return;
}
