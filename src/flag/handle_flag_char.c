/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** handle_flag_char.c
*/
#include "../../include/printf.h"

static int get_new_width(int len, format_t *option)
{
    int width = 0;

    if (len <= option->width) {
        width = option->width - len;
    } else if (len > option->width) {
        return width;
    }
    return width;
}

static void check_width(char *str, int *count, format_t *option)
{
    int new_width = 0;
    int len = my_strlen(str);

    if (option->width != 0) {
        new_width = get_new_width(len, option);
        for (int i = 0; i != new_width; i++) {
            (*count) += my_putchar(' ');
        }
    }
    return;
}

int handle_flag_char(char *str, int *count, format_t *option)
{
    flag_t all_flag = {0};
    int len = my_strlen(str);
    int new_width = 0;
    char *new_str = malloc(sizeof(char) * option->precision + 1);

    verify_flag(&all_flag, option);
    if (len > option->precision && option->precision != 0) {
        new_str = my_strncpy(new_str, str, option->precision);
        check_width(new_str, count, option);
        my_putstr(new_str, count);
        free(new_str);
        return 0;
    }
    if (option->width != 0) {
        new_width = get_new_width(len, option);
        for (int i = 0; i != new_width; i++)
            (*count) += my_putchar(' ');
    }
    my_putstr(str, count);
    return 0;
}
