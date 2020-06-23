/*
** EPITECH PROJECT, 2019
** quenelle
** File description:
** change_order.c
*/

#include "my.h"

int sorted_or_not(char *str1, char *str2)
{
    int inc = 0;

    while (str1[inc] == str2[inc] && str1[inc] != '\0' && str2[inc] != '\0')
        inc = inc + 1;
    return (str1[inc] - str2[inc]);
}

char *my_strdup(char *copy)
{
    char *new = malloc(sizeof(char) * (my_strlen(copy) + 1));

    if (new == NULL)
        return (NULL);
    if (my_strcpy(new, copy, 0) == NULL)
        return (NULL);
    return (new);
}

char **lets_change_order(char **folder, int tmp, int cy)
{
    char *new = NULL;

    if (folder[tmp] != NULL) {
        if (sorted_or_not(folder[cy], folder[tmp]) > 0) {
            new = my_strdup(folder[cy]);
            folder[cy] = my_strdup(folder[tmp]);
            folder[tmp] = my_strdup(new);
        }
    }
    return (folder);
}

char **change_order(char **folder, int size)
{
    int cy = 0;
    int tmp = 0;

    while (cy <= size) {
        tmp = cy + 1;
        while (tmp <= size) {
            lets_change_order(folder, tmp, cy);
            tmp = tmp + 1;
        }
        cy = cy + 1;
    }
    return (folder);
}