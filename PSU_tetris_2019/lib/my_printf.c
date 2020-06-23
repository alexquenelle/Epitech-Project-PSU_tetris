/*
** EPITECH PROJECT, 2019
** new_navy
** File description:
** my_printf.c
*/

#include "my.h"

void opt_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void opt_str(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void opt_dec(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void my_option(char flag, va_list(ap))
{
    int inc = 0;
    const char *my_flags = "csd";
    void (*board[3])(va_list) = {&opt_char, &opt_str, &opt_dec};

    while (my_flags[inc] != '\0') {
        if (my_flags[inc] == flag)
            board[inc](ap);
        inc = inc + 1;
    }
}

void my_printf(char *str, ...)
{
    va_list(ap);
    va_start(ap, *str);
    int inc = 0;

    while (str[inc] != '\0') {
        if (str[inc] == '%') {
            my_option(str[inc + 1], ap);
            inc = inc + 1;
        }
        else
            my_putchar(str[inc]);
        inc = inc + 1;
    }
}