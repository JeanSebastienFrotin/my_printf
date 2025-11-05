/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdarg.h>
    #include <stdio.h>
    #include <unistd.h>

    #define UNUSED __attribute__((unused))

int my_putchar(FILE *stream, char c);
int my_putstr(FILE *stream, char const *str);
int my_put_nbr(FILE *stream, int nb);
int my_putfloat(FILE *stream, double fl, int precision);
int mini_fprintf(FILE *stream, const char *format, ...);
int is_str(FILE *stream, va_list arg);
int is_flt(FILE *stream, va_list arg);
int is_int(FILE *stream, va_list arg);
int is_chr(FILE *stream, va_list arg);
int is_pct(FILE *stream, UNUSED va_list arg);

#endif
