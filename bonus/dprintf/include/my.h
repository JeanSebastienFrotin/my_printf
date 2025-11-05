/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdarg.h>
    #include <unistd.h>

    #define UNUSED __attribute__((unused))

int my_putchar(int fd, char c);
int my_putstr(int fd, char const *str);
int my_put_nbr(int fd, int nb);
int my_putfloat(int fd, double fl, int precision);
int mini_dprintf(int fd, const char *format, ...);
int is_str(int fd, va_list arg);
int is_flt(int fd, va_list arg);
int is_int(int fd, va_list arg);
int is_chr(int fd, va_list arg);
int is_pct(int fd, UNUSED va_list arg);

#endif
