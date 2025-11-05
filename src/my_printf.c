/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my_printf
*/
#include "../include/printf.h"
#include "../include/tab.h"

int check_type(va_list arg, format_t *option, int *count)
{
    for (int i = 0; TAB[i].specifier != '\0'; i++) {
        if (!strncmp(&TAB[i].specifier, &option->specifier, 1))
            TAB[i].func(arg, count, option);
    }
    return 0;
}

int fill_struct(const char *format, int *i, format_t *option)
{
    if (format[*i] == '%' && format[*i + 1] != '\0') {
        if (is_specifier(format, i) == 1) {
            (*i)++;
            parse_format(format, i, option);
            return 1;
        }
    }
    return 0;
}

int parsing(const char *format, va_list arg, int *count, format_t *option)
{
    init_option(option);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == '\0')
            return 0;
        if (fill_struct(format, &i, option) == 1) {
            check_type(arg, option, count);
            reset_option(option);
        } else {
            *count += my_putchar(format[i]);
        }
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list arg;
    int count = 0;
    format_t *option = malloc(sizeof(format_t));

    if (option == NULL)
        return 84;
    va_start(arg, format);
    parsing(format, arg, &count, option);
    va_end(arg);
    free(option);
    return count;
}
