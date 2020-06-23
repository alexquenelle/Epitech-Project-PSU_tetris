/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** calc_fct.c
*/

#include "my.h"

int my_strlen(char *str)
{
    int inc = 0;

    while (str[inc] != '\0')
        inc = inc + 1;
    return (inc);
}

int my_strlen_custom(char *str)
{
    int inc = 0;

    while (str[inc] != '.')
        inc = inc + 1;
    return (inc);
}

int get_nbr_tetriminos(char *path)
{
    struct dirent *readed;
    int nbr = 0;
    DIR *folder = NULL;
    folder = opendir(path);

    if (folder == NULL)
        return (-1);
    while ((readed = readdir(folder))) {
        if (readed->d_name[0] != '.')
            nbr = nbr + 1;
    }
    closedir(folder);
    return (nbr);
}

int my_strsize(char *str)
{
    int inc = 0;
    int nbr = 0;

    while (str[inc] != '\0') {
        if (str[inc] == '\n')
            nbr = nbr + 1;
        inc = inc + 1;
    }
    return (nbr);
}

int my_returnlen(char *str)
{
    int inc = 0;

    while (str[inc] != '\n' && str[inc] != '\0')
        inc = inc + 1;
    return (inc);
}