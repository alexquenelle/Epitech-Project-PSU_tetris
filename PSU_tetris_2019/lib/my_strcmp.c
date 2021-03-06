/*
** EPITECH PROJECT, 2019
** src
** File description:
** my_strcmp.c
*/

#include "my.h"

int game_cmp(char *str1, char *str2)
{
    int inc = 0;

    while (str1[inc] == str2[inc] && str1[inc] != '\0' && str2[inc] != '\0')
    {
        inc = inc + 1;
    }
    return (str1[inc] - str2[inc]);
}

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    if (str1 == NULL && str2 == NULL)
        return (1);
    if (str1 == NULL || my_strlen(str1) != my_strlen(str2))
        return (0);
    while (str1[i] != '\0') {
        if (str1[i] != str2[i])
            return (0);
        i = i + 1;
    }
    return (1);
}

int my_strcmp_custom(char *str1, char *str2)
{
    int i = 0;

    if (str1 == NULL && str2 == NULL)
        return (1);
    if (str1 == NULL)
        return (0);
    while (str1[i] != '=') {
        if (str1[i] != str2[i])
            return (0);
        i = i + 1;
    }
    return (1);
}