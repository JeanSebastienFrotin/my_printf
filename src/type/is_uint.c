/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** is_uint.c
*/
#include "../../include/printf.h"

void is_uint(va_list arg, int *count, format_t *option)
{
    int mysigned = 0;
    unsigned int myunsigned = 0;

    mysigned = va_arg(arg, unsigned int);
    myunsigned = mysigned;
    handle_flag_int(myunsigned, count, option);
    return;
}
