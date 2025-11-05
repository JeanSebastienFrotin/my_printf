/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** tab.h
*/

#ifndef TAB_H_
    #define TAB_H_
    #include "printf.h"

typedef struct find_arg {
    char specifier;
    void (*func)(va_list arg, int *count, format_t *option);
} find_arg_t;

const find_arg_t char_to_flag[] = {
    {'d', &is_int},
    {'i', &is_int},
    {'u', &is_uint},
    {'o', &is_octal},
    {'x', &is_uhexaint},
    {'X', &is_uhexaintupper},
    {'f', &is_float},
    {'F', &is_floatupper},
    {'e', &is_scien},
    {'E', &is_scienupper},
    {'g', &is_short},
    {'G', &is_shortupper},
    //{'a', &is_hexafloat},
    //{'A', &is_hexafloatupper},
    {'c', &is_char},
    {'s', &is_string},
    {'p', &is_adress},
    {'n', &is_n},
    {'%', &is_pourcent},
    {'\0', NULL}
};

#endif
