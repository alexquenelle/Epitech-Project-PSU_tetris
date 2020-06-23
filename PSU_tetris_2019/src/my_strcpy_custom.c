/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** my_strcpy_custom.c
*/

#include "my.h"

char *my_strcpy_custom(char *new, char *src, int inc)
{
    int start = 0;

    if (new == NULL || src == NULL)
        return (NULL);
    while (src[inc] != '\0') {
        if (src[inc] == ',')
            return (new);
        new[start] = src[inc];
        inc = inc + 1;
        start = start + 1;
    }
    new[start] = '\0';
    return (new);
}