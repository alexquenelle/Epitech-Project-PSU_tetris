/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** tetri_rotate.c
*/

#include "my.h"

int find_bigger_line(char **board, int inc)
{
    int cy = inc;
    int save = 0;
    int now = 0;

    while (board[cy] != NULL) {
        now = my_strlen(board[cy]);
        if (now > save) {
            save = now;
            now = 0;
        }
        cy = cy + 1;
    }
    return (save);
}

int my_arraysize(char **board)
{
    int cy = 0;

    while (board[cy] != NULL)
        cy = cy + 1;
    return (cy);
}

char *cpy_rotate_me(char **piece, int size, int inc)
{
    int cx = 0;
    int cpy = 0;
    char *new = malloc(sizeof(char) * (size + 2));

    if (new == NULL)
        return (NULL);
    while (size >= 0) {
        new[cpy] = piece[size][inc];
        cpy = cpy + 1;
        size = size - 1;
    }
    new[cpy] = '\0';
    return (new);
}

char **rotate_me(char **piece, int size, int len)
{
    int cy = 0;
    int inc = 0;
    char **new = malloc(sizeof(char *) * (len + 1));

    if (new == NULL)
        return (NULL);

    while (piece[0][inc] != '\0') {
        new[cy] = cpy_rotate_me(piece, size, inc);
        if (new[cy] == NULL)
            return (NULL);
        cy = cy + 1;
        inc = inc + 1;
    }
    new[cy] = NULL;
    return (new);
}