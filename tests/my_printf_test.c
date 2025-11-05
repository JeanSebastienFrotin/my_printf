/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** test_myprintf.c
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/printf.h"

//-----------------test my_printf int---------------------//

Test(my_printf, width_10_positive)
{
    cr_redirect_stdout();
    my_printf("Number: %10d\n", 42);
    cr_assert_stdout_eq_str("Number:         42\n");
}

Test(my_printf, width_10_zero_padding_positive)
{
    cr_redirect_stdout();
    my_printf("Number: %010d\n", 42);
    cr_assert_stdout_eq_str("Number: 0000000042\n");
}

Test(my_printf, precision_4_positive)
{
    cr_redirect_stdout();
    my_printf("Number: %.4d\n", 42);
    cr_assert_stdout_eq_str("Number: 0042\n");
}

Test(my_printf, width_10_plus_sign_positive)
{
    cr_redirect_stdout();
    my_printf("Number: %+-10d\n", 42);
    cr_assert_stdout_eq_str("Number: +42       \n");
}

Test(my_printf, width_5_large_positive)
{
    cr_redirect_stdout();
    my_printf("Number: %5d\n", 123456);
    cr_assert_stdout_eq_str("Number: 123456\n");
}

Test(my_printf, width_10_negative)
{
    cr_redirect_stdout();
    my_printf("Number: %10d\n", -42);
    cr_assert_stdout_eq_str("Number:        -42\n");
}

Test(my_printf, width_10_zero_padding_negative)
{
    cr_redirect_stdout();
    my_printf("Number: %010d\n", -42);
    cr_assert_stdout_eq_str("Number: -000000042\n");
}

Test(my_printf, precision_4_negative)
{
    cr_redirect_stdout();
    my_printf("Number: %.4d\n", -42);
    cr_assert_stdout_eq_str("Number: -0042\n");
}

Test(my_printf, width_10_plus_sign_negative)
{
    cr_redirect_stdout();
    my_printf("Number: %+-10d\n", -42);
    cr_assert_stdout_eq_str("Number: -42       \n");
}

Test(my_printf, width_5_large_negative)
{
    cr_redirect_stdout();
    my_printf("Number: %5d\n", -123456);
    cr_assert_stdout_eq_str("Number: -123456\n");
}

//-----------------test my_printf string---------------------//

Test(my_printf, no_flag)
{
    cr_redirect_stdout();
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, widht_20)
{
    cr_redirect_stdout();
    my_printf("'%20s'\n", "test");
    cr_assert_stdout_eq_str("'                test'\n");
}

Test(my_printf, widht_with_precision)
{
    cr_redirect_stdout();
    my_printf("'%5.3s'\n", "abcdef");
    cr_assert_stdout_eq_str("'  abc'\n");
}

Test(my_printf, widht_with_precision_2)
{
    cr_redirect_stdout();
    my_printf("'%10.5s'\n", "abcdef");
    cr_assert_stdout_eq_str("'     abcde'\n");
}

Test(my_printf, small_width)
{
    cr_redirect_stdout();
    my_printf("'%5s'\n", "This is a long string");
    cr_assert_stdout_eq_str("'This is a long string'\n");
}

//-----------------test my_printf float---------------------//

Test(my_printf, flag_f)
{
    double test_float = 15.1234;

    cr_redirect_stdout();
    my_printf("%f", test_float);
    cr_assert_stdout_eq_str("15.123400");
}

Test(my_printf, flag_f_neg)
{
    double test_float = -15.1234;

    cr_redirect_stdout();
    my_printf("%f", test_float);
    cr_assert_stdout_eq_str("-15.123400");
}

Test(my_printf, flag_f_width)
{
    double test_float = 15.1234;

    cr_redirect_stdout();
    my_printf("%12f", test_float);
    cr_assert_stdout_eq_str("   15.123400");
}

Test(my_printf, flag_f_width_plus)
{
    double test_float = 15.1234;

    cr_redirect_stdout();
    my_printf("%+12f", test_float);
    cr_assert_stdout_eq_str("  +15.123400");
}

Test(my_printf, float_with_space_flag)
{
    cr_redirect_stdout();
    my_printf("float = % f", 3.14);
    cr_assert_stdout_eq_str("float =  3.140000");
}

Test(my_printf, float_minus_flag_negative)
{
    cr_redirect_stdout();
    my_printf("float = %-10.2f", -42.5);
    cr_assert_stdout_eq_str("float = -42.50    ");
}

Test(my_printf, float_zero_flag_negative)
{
    cr_redirect_stdout();
    my_printf("float = %010.2f", -42.5);
    cr_assert_stdout_eq_str("float = -000042.50");
}

Test(my_printf, float_with_minus_flag)
{
    cr_redirect_stdout();
    my_printf("float = %-10.2f!", 3.14);
    cr_assert_stdout_eq_str("float = 3.14      !");
}

Test(my_printf, flag_f_weird)
{
    double test_float = 15.1234;

    cr_redirect_stdout();
    my_printf("%-+10.2f", test_float);
    cr_assert_stdout_eq_str("+15.12    ");
}

Test(my_printf, flag_F)
{
    double test_float = 15.1234;

    cr_redirect_stdout();
    my_printf("%F", test_float);
    cr_assert_stdout_eq_str("15.123400");
}

Test(my_printf, flag_F_neg)
{
    double test_float = -15.1234;

    cr_redirect_stdout();
    my_printf("%F", test_float);
    cr_assert_stdout_eq_str("-15.123400");
}

Test(my_printf, flag_F_width)
{
    double test_float = 15.1234;

    cr_redirect_stdout();
    my_printf("%12F", test_float);
    cr_assert_stdout_eq_str("   15.123400");
}

Test(my_printf, flag_F_width_plus)
{
    double test_float = 15.1234;

    cr_redirect_stdout();
    my_printf("%+12F", test_float);
    cr_assert_stdout_eq_str("  +15.123400");
}

//-----------------test my_printf---------------------//

Test(my_printf, flag_pourcent)
{
    cr_redirect_stdout();
    my_printf("hello %%");
    cr_assert_stdout_eq_str("hello %");
}

Test(my_printf, pourcent_empty)
{
    cr_redirect_stdout();
    my_printf("%");
    cr_assert_stdout_eq_str("");
}

Test(my_printf, double_flag)
{
    cr_redirect_stdout();
    my_printf("%++d", 78);
    cr_assert_stdout_eq_str("+78");
}

Test(my_printf, multiple_flags)
{
    cr_redirect_stdout();
    my_printf("%# d", 78);
    cr_assert_stdout_eq_str(" 78");
}

Test(my_printf, bad_specifier)
{
    cr_redirect_stdout();
    my_printf("hello%y");
    cr_assert_stdout_eq_str("hello%y");
}

Test(my_printf, flag_c)
{
    char test_char = 'd';

    cr_redirect_stdout();
    my_printf("hello worl%c", test_char);
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, flag_s)
{
    char *test_array = "world";

    cr_redirect_stdout();
    my_printf("hello %s", test_array);
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, flag_o)
{
    char test_octal = 63;

    cr_redirect_stdout();
    my_printf("octal of %d is %o", test_octal, test_octal);
    cr_assert_stdout_eq_str("octal of 63 is 77");
}

Test(my_printf, flag_o_width)
{
    char test_octal = 63;

    cr_redirect_stdout();
    my_printf("octal of %d is %-6o", test_octal, test_octal);
    cr_assert_stdout_eq_str("octal of 63 is 77     ");
}

Test(my_printf, flag_o_zero)
{
    char test_octal = 0;

    cr_redirect_stdout();
    my_printf("octal of %d is %o", test_octal, test_octal);
    cr_assert_stdout_eq_str("octal of 0 is 0");
}

Test(my_printf, flag_e)
{
    double test_scien = 15.1234;

    cr_redirect_stdout();
    my_printf("scientific number of 15.1234 is %e", test_scien);
    cr_assert_stdout_eq_str("scientific number of 15.1234 is 1.512340e+01");
}

Test(my_printf, flag_e_neg)
{
    double test_scien = -15.1234;

    cr_redirect_stdout();
    my_printf("scientific number of -15.1234 is %e", test_scien);
    cr_assert_stdout_eq_str("scientific number of -15.1234 is -1.512340e+01");
}

Test(my_printf, flag_e_little)
{
    double test_scien = 0.13;

    cr_redirect_stdout();
    my_printf("scientific number of 0.13 is %e", test_scien);
    cr_assert_stdout_eq_str("scientific number of 0.13 is 1.300000e-01");
}

Test(my_printf, flag_E)
{
    double test_scien = 15.1234;

    cr_redirect_stdout();
    my_printf("scientific number of 15.1234 is %E", test_scien);
    cr_assert_stdout_eq_str("scientific number of 15.1234 is 1.512340E+01");
}

Test(my_printf, flag_E_neg)
{
    double test_scien = -15.1234;

    cr_redirect_stdout();
    my_printf("scientific number of -15.1234 is %E", test_scien);
    cr_assert_stdout_eq_str("scientific number of -15.1234 is -1.512340E+01");
}

Test(my_printf, flag_E_little)
{
    double test_scien = 0.13;

    cr_redirect_stdout();
    my_printf("scientific number of 0.13 is %E", test_scien);
    cr_assert_stdout_eq_str("scientific number of 0.13 is 1.300000E-01");
}

Test(my_printf, flag_x)
{
    int test_int_x = 79010;

    cr_redirect_stdout();
    my_printf("hexadecimal of 79010 is %x", test_int_x);
    cr_assert_stdout_eq_str("hexadecimal of 79010 is 134a2");
}

Test(my_printf, flag_x_width)
{
    int value = 255;

    cr_redirect_stdout();
    my_printf("%5x", value);
    cr_assert_stdout_eq_str("   ff");
}

Test(my_printf, flag_x_zero)
{
    int test_int_x = 0;

    cr_redirect_stdout();
    my_printf("hexadecimal of 0 is %x", test_int_x);
    cr_assert_stdout_eq_str("hexadecimal of 0 is 0");
}

Test(my_printf, flag_X)
{
    int test_int_X = 79010;

    cr_redirect_stdout();
    my_printf("hexadecimal of 79010 is %X", test_int_X);
    cr_assert_stdout_eq_str("hexadecimal of 79010 is 134A2");
}

Test(my_printf, flag_X_width)
{
    int value = 255;

    cr_redirect_stdout();
    my_printf("%5X", value);
    cr_assert_stdout_eq_str("   FF");
}

Test(my_printf, flag_X_zero)
{
    int test_int_X = 0;

    cr_redirect_stdout();
    my_printf("hexadecimal of 0 is %X", test_int_X);
    cr_assert_stdout_eq_str("hexadecimal of 0 is 0");
}

Test(my_printf, flag_u)
{
    char test_uint = 1;

    cr_redirect_stdout();
    my_printf("hello world%u", test_uint);
    cr_assert_stdout_eq_str("hello world1");
}

Test(my_printf, flag_n)
{
    int count = 0;;
    cr_redirect_stdout();
    my_printf("Hello%n", &count);
    cr_assert_eq(count, 5);
}

Test(my_printf, flag_p_null)
{
    void *ptr = NULL;
    cr_redirect_stdout();
    my_printf("%p", ptr);
    cr_assert_stdout_eq_str("(nil)");
}

Test(my_printf, flag_p)
{
    int a = 42;
    int *ptr = &a;
    char buffer[100];

    cr_redirect_stdout();
    snprintf(buffer, 100, "%p\n", ptr);
    my_printf("%p\n", ptr);
    cr_assert_stdout_eq_str(buffer);
}

//-----------------test functions parsing---------------------//

Test(my_printf, check_length_hh)
{
    int test_int = 12;

    cr_redirect_stdout();
    my_printf("%hhd", test_int);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, check_length_ll)
{
    int test_int = 12;

    cr_redirect_stdout();
    my_printf("%lld", test_int);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, check_length_basic)
{
    int test_int = 12;

    cr_redirect_stdout();
    my_printf("%ld", test_int);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, check_flag_basic)
{
    int test_int = 12;

    cr_redirect_stdout();
    my_printf("%+d", test_int);
    cr_assert_stdout_eq_str("+12");
}

Test(my_printf, check_precision_star)
{
    int test_int = 12;

    cr_redirect_stdout();
    my_printf("%.*d", test_int);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, check_width_star)
{
    int test_int = 12;

    cr_redirect_stdout();
    my_printf("%*d", test_int);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, flag_g)
{
    cr_redirect_stdout();
    double val = 0.00001;
    my_printf("value = %g", val);
    cr_assert_stdout_eq_str("value = 1.000000e-05");
}

Test(my_printf, flag_g_f)
{
    cr_redirect_stdout();
    double val = 7.5;
    my_printf("value = %.5g", val);
    cr_assert_stdout_eq_str("value = 7.50000");
}

Test(my_printf, flag_G)
{
    cr_redirect_stdout();
    double val = 0.00001;
    my_printf("value = %G", val);
    cr_assert_stdout_eq_str("value = 1.000000E-05");
}

Test(my_printf, flag_G_f)
{
    cr_redirect_stdout();
    double val = 7.5;
    my_printf("value = %.5G", val);
    cr_assert_stdout_eq_str("value = 7.50000");
}

//-----------------test functions utils---------------------//

Test(my_strncat, basic_concat)
{
    char dest[100] = "Hello";
    my_strncat(dest, " World", 3);
    cr_assert_str_eq(dest, "Hello Wo");
}

Test(my_strncat, zero_n)
{
    char dest[100] = "Init";
    my_strncat(dest, "Ignored", 0);
    cr_assert_str_eq(dest, "Init");
}

Test(my_strncat, empty_src)
{
    char dest[100] = "Base";
    my_strncat(dest, "", 5);
    cr_assert_str_eq(dest, "Base");
}

Test(my_strdup, normal_string)
{
    char *src = "Hello world";
    char *dup = my_strdup(src);

    cr_assert_str_eq(dup, src);
    free(dup);
}

Test(my_strdup, empty_string)
{
    char *src = "";
    char *dup = my_strdup(src);

    cr_assert_str_eq(dup, src);
    free(dup);
}

Test(my_put_nbr, positive_number)
{
    int count = 12;

    cr_redirect_stdout();
    my_put_nbr(12345, &count);
    cr_assert_stdout_eq_str("12345");
}

Test(my_put_nbr, negative_number)
{
    int count = 12;

    cr_redirect_stdout();
    my_put_nbr(-42, &count);
    cr_assert_stdout_eq_str("-42");
}

Test(my_put_nbr, int_min)
{
    int count = 12;

    cr_redirect_stdout();
    my_put_nbr(-2147483648, &count);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_put_nbr, zero)
{
    int count = 12;

    cr_redirect_stdout();
    my_put_nbr(0, &count);
    cr_assert_stdout_eq_str("0");
}

Test(my_putchar, write_1_char)
{
    cr_redirect_stdout();
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_revstr, reverse_normal_string)
{
    char str[] = "abcdef";
    cr_assert_str_eq(my_revstr(str), "fedcba");
}

Test(my_putnbr_base, negative_number_in_hex)
{
    int count = 0;

    cr_redirect_stdout();
    my_putnbr_base(-255, "0123456789abcdef", &count);
    cr_assert_stdout_eq_str("ff");
}

Test(my_strncpy, copy_exact_length)
{
    char dest[100] = "Hello";
    my_strncpy(dest, "Goodbye", 7);
    cr_assert_str_eq(dest, "Goodbye");
}
