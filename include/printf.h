/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef PRINTF_H
    #define PRINTF_H

    #include <limits.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>

    #define UNUSED __attribute__((unused))
    #define TAB char_to_flag

typedef struct format_s {
    char flags[6];
    long long width;
    int width_ast;
    long long precision;
    int precision_ast;
    int precision_dot;
    char length[3];
    char specifier;
} format_t;

typedef struct flag_s {
    int minus;
    int plus;
    int space;
    int hashtag;
    int zero;
} flag_t;

int my_putchar(char c);
int my_putstr(char const *str, int *count);
int my_strlen(char const *str);
int my_put_nbr(int nb, int *count);
char *my_revstr(char *str);
void my_putfloat(double num, int *count, int len_dec);
int my_putnbr_base(long long nbr, char const *base, int *count);
char *my_strncat(char *dest, char const *src, int n);
char *my_strdup(char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int parse_flag(const char *format, int *i, format_t *option);
int parse_precision(const char *format, int *i, format_t *option);
int parse_width(const char *format, int *i, format_t *option);
int parse_length(const char *format, int *i, format_t *option);
int parse_specifier(const char *format, int *i, format_t *option);
int parse_format(const char *format, int *i, format_t *option);
int init_option(format_t *option);
int reset_option(format_t *option);
int my_printf(const char *format, ...);
void is_int(va_list arg, int *count, format_t *option);
void is_char(va_list arg, int *count, UNUSED format_t *option);
void is_pourcent(UNUSED va_list arg, int *count, UNUSED format_t *option);
void is_string(va_list arg, int *count, format_t *option);
void is_uint(va_list arg, int *count, format_t *option);
void is_octal(va_list arg, int *count, UNUSED format_t *option);
void is_floatupper(va_list arg, int *count, format_t *option);
void is_float(va_list arg, int *count, format_t *option);
void is_uhexaint(va_list arg, int *count, UNUSED format_t *option);
void is_uhexaintupper(va_list arg, int *count, UNUSED format_t *option);
void is_scien(va_list arg, int *count, format_t *option);
void is_scienupper(va_list arg, int *count, format_t *option);
void is_n(va_list arg, int *count, UNUSED format_t *option);
void is_adress(va_list arg, int *count, UNUSED format_t *option);
void handle_flag_int(long long myint, int *count, format_t *option);
int is_specifier(const char *format, int *i);
int to_skip(char c);
int char_is_in(char c);
void handle_precision(long long myint, int *count, format_t *option);
int handle_flag_char(char *str, int *count, format_t *option);
int my_putstr_flag(char const *str, int *count, int len);
void init_flag(flag_t *all_flag);
void verify_flag(flag_t *all_flag, format_t *option);
void handle_flag_float(double mynbr, int *count, format_t *option);
int get_exponent(double *num);
void print_num(double num, int *count);
void print_exponent(int exponent, int *count);
void is_short(va_list arg, int *count, format_t *option);
void print_exponent_upper(int exponent, int *count);
void is_shortupper(va_list arg, int *count, format_t *option);

#endif
