/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** my_cpy_array_list.c
*/

#include "my.h"

char **cpy_array(char **board, int inc, int min)
{
    int cy = inc;
    int cpy = 0;
    int len = my_arraysize(board) - min;
    char **new = malloc(sizeof(char *) * (len + 1));

    if (new == NULL)
        return (NULL);

    while (board[cy] != NULL) {
        new[cpy] = my_strdup(board[cy]);
        if (new[cpy] == NULL)
            return (NULL);
        cy = cy + 1;
        cpy = cpy + 1;
    }
    new[cpy] = NULL;
    return (new);
}

int my_arraylistlen(char ***board)
{
    int cy = 0;

    while (board[cy] != NULL)
        cy = cy + 1;
    return (cy);
}

char ***rm_wrong_tetrimos(char ***board, int cy)
{
    int cpy = 0;
    int save = 0;
    int nbr = my_arraylistlen(board);
    char ***new = malloc(sizeof(char **) * (nbr + 1));

    if (new == NULL)
        return (NULL);
    while (cpy < cy && board[cpy] != NULL) {
        new[cpy] = cpy_array(board[cpy], 0, 0);
        cpy = cpy + 1;
    }
    save = cpy;
    cpy = cpy + 1;
    while (board[cpy] != NULL) {
        new[save] = cpy_array(board[cpy], 0, 0);
        cpy = cpy + 1;
        save = save + 1;
    }
    new[save] = NULL;
    return (new);
}