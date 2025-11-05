/*
** EPITECH PROJECT, 2025
** tab.h
** File description:
** tab.h
*/

#ifndef TAB_H
    #define TAB_H

    #include "my.h"
    #include <stdlib.h>

typedef struct ptr_func_s {
    char specifier;
    int (*func)(int fd, va_list arg);
} ptr_func_t;

const ptr_func_t tab_s[] = {
    {'d', &is_int},
    {'i', &is_int},
    {'s', &is_str},
    {'c', &is_chr},
    {'f', &is_flt},
    {'%', &is_pct},
    {'\0', NULL}
};

#endif
