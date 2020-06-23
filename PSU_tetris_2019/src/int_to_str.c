/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** int_to_str.c
*/

#include "my.h"

int my_intlen(int nbr)
{
    int inc = 0;
    if (nbr < 0)
    {
        nbr = nbr * -1;
        inc = 1;
    }
    while (nbr > 0)
    {
        inc = inc + 1;
        nbr = nbr / 10;
    }
    return (inc);
}

char *my_convert(int nbr)
{
    int inc = my_intlen(nbr);
    char *str = malloc(sizeof(char *) * (inc + 1));
    int save = inc;

    if (nbr < 0)
    {
        nbr = nbr * -1;
        str[0] = '-';
    }
    while (nbr > 0)
    {
        str[inc - 1] = nbr % 10 + 48;
        inc = inc - 1;
        nbr = nbr / 10;
    }
    str[save] = '\0';
    return (str);
}