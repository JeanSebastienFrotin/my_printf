/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** handle_struct.c
*/
#include "../include/printf.h"

int init_option(format_t *option)
{
    for (int i = 0; i < 6; i++) {
        option->flags[i] = '\0';
    }
    option->width = 0;
    option->width_ast = 0;
    option->precision = 0;
    option->precision_ast = 0;
    option->precision_dot = 0;
    for (int i = 0; i < 3; i++) {
        option->length[i] = '\0';
    }
    option->specifier = '\0';
    return 0;
}

int reset_option(format_t *option)
{
    for (int i = 0; i < 6; i++) {
        option->flags[i] = '\0';
    }
    option->width = 0;
    option->width_ast = 0;
    option->precision = 0;
    option->precision_ast = 0;
    option->precision_dot = 0;
    for (int i = 0; i < 3; i++) {
        option->length[i] = '\0';
    }
    option->specifier = '\0';
    return 0;
}
