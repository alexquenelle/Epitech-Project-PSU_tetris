/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** piece_to_board.c
*/

#include "my.h"

char **cpy_piece_board(tetris_t *tetris, char *str, int x, int y)
{
    int inc = 0;

    while (str[inc] != '\0') {
        if (str[inc] != ' ' && (tetris->nid->bd[y][x] > '0' && tetris->nid->bd[y][x] < '9'))
            tetris->nid->bd[y][x] = 'X';
        else if (str[inc] != ' ')
            tetris->nid->bd[y][x] = tetris->info->col + 48;
        inc = inc + 1;
        x = x + 1;
    }
    return (tetris->nid->bd);
}

char **copie_piece_to_board(char **piece, int x, int y, tetris_t *tetris)
{
    int cy = 0;

    while (piece[cy] != NULL) {
        cpy_piece_board(tetris, piece[cy], x, y);
        y = y + 1;
        cy = cy + 1;
    }
    return (tetris->nid->bd);
}