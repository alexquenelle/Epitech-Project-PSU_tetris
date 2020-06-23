/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** cpy_fct.c
*/

#include "my.h"

char *my_strcpy(char *new, char *src, int inc)
{
    int start = 0;

    if (new == NULL || src == NULL)
        return (NULL);
    while (src[start] != '\0') {
        new[inc] = src[start];
        inc = inc + 1;
        start = start + 1;
    }
    new[inc] = '\0';
    return (new);
}

char *my_strcat_add(char *bfr, char *last, char add)
{
    int len = my_strlen(bfr);
    int inc = my_strlen(last);
    char *new = malloc(sizeof(char) * (len + inc + 2));

    if (new == NULL || bfr == NULL || last == NULL)
        return (NULL);
    if (my_strcpy(new, bfr, 0) == NULL)
        return (NULL);
    new[len] = add;
    if (my_strcpy(new, last, len + 1) == NULL)
        return (NULL);
    new[len + inc + 1] = '\0';
    return (new);
}

char *cpy_piece_to_array(char *piece, int inc, int len)
{
    int cpy = 0;
    char *new = malloc(sizeof(char) * (len + 1));

    if (new == NULL || piece == NULL)
        return (NULL);
    while (piece[inc] != '\n' && piece[inc] != '\0')
    {
        new[cpy] = piece[inc];
        cpy = cpy + 1;
        inc = inc + 1;
    }
    new[cpy] = '\0';
    return (new);
}

char **piece_to_array(char **tetri, char *piece)
{
    int cy = 0;
    int cx = 0;
    int inc = 0;
    int len = 0;

    if (tetri == NULL || piece == NULL)
        return (NULL);
    len = my_returnlen(piece);
    while (piece[inc] != '\0') {
        tetri[cy] = cpy_piece_to_array(piece, inc, len);
        if (tetri[cy] == NULL)
            return (NULL);
        while (piece[inc] != '\n' && piece[inc] != '\0')
            inc = inc + 1;
        inc = inc + 1;
        cy = cy + 1;
    }
    tetri[cy] = NULL;
    return (tetri);
}

char **tetriminos_to_array(char *path)
{
    char **tetri = NULL;
    char *piece = open_path(path);

    if (piece == NULL)
        return (NULL);
    tetri = malloc(sizeof(char *) * (my_strsize(piece) + 1));
    if (tetri == NULL)
        return (NULL);
    if (piece_to_array(tetri, piece) == NULL)
        return (NULL);
    return (tetri);
}