/*
** EPITECH PROJECT, 2019
** new_navy
** File description:
** my_display.c
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int inc = 0;

    while (str[inc] != '\0') {
        my_putchar(str[inc]);
        inc = inc + 1;
    }
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        if (nb > -10) {
            my_putchar('-');
            my_putchar((nb * -1) + 48);
        } else {
            my_putchar('-');
            my_put_nbr((nb / 10) * -1);
            my_putchar(((nb % 10) * -1) + 48);
        }
    } else if (nb < 10 && nb > 0) {
        my_putchar(nb + 48);
    } else {
        if (nb >= 10) {
            my_put_nbr(nb / 10);
        }
        my_putchar((nb % 10) + '0');
    }
}

int my_atoi(char *str)
{
    int nbr = 0;
    int neg = 1;
    int inc = 0;

    while (str[inc] == '+' || str[inc] == '-') {
        if (str[inc] == '-')
            neg = neg * -1;
        inc = inc + 1;
    }
    while (str[inc] != '\0') {
        if (str[inc] >= '0' && str[inc] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[inc] - 48;
            inc = inc + 1;
        }
        else
            return (nbr * neg);
    }
    return (nbr * neg);
}