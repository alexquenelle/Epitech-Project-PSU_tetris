/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** create_game_board.c
*/

#include "my.h"

char *cpy_start_end_line(int x)
{
    int cpy = 0;
    char *new = malloc(sizeof(char) * (x + 1));

    if (new == NULL)
        return (NULL);
    while (cpy < x) {
        new[cpy] = '*';
        cpy = cpy + 1;
    }
    new[cpy] = '\0';
    return (new);
}

char *cpy_line_to_board(int x, int y)
{
    int inc = 1;
    char *new = malloc(sizeof(char) * (x + 1));

    if (new == NULL)
        return (NULL);
    new[0] = '*';
    while ((inc + 1) < x) {
        new[inc] = ' ';
        inc = inc + 1;
    }
    new[inc] = '*';
    new[inc + 1] = '\0';
    return (new);
}

char **create_rest(char **board, int x, int y)
{
    int cy = 1;
    int cx = 1;

    while ((cy + 1) < y) {
        board[cy] = cpy_line_to_board(x, y);
        if (board[cy] == NULL)
            return (NULL);
        cy = cy + 1;
    }
    board[cy] = cpy_start_end_line(x);
    if (board[cy] == NULL)
        return (NULL);
    board[cy + 1] = NULL;
    return (board);
}

char **create_game_board(int x, int y)
{
    int cy = 1;
    int cx = 1;
    char **board = malloc(sizeof(char *) * (y + 1));

    if (board == NULL)
        return (NULL);
    board[0] = cpy_start_end_line(x);
    if (board[0] == NULL)
        return (NULL);
    if (create_rest(board, x, y) == NULL)
        return (NULL);
    return (board);
}