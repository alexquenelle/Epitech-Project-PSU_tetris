/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** check_all_pieces.c
*/

#include "my.h"

int check_piece_ret(char *str)
{
    int inc = 0;

    while (str[inc] != '\0') {
        if (str[inc] != '*' && str[inc] != ' ')
            return (84);
        inc = inc + 1;
    }
    return (0);
}

int check_piece(char **board)
{
    int cy = 1;

    while (board[cy] != NULL) {
        if (check_piece_ret(board[cy]) == 84)
            return (84);
        cy = cy + 1;
    }
    return (0);
}

int check_all_pieces(tetris_t *tetris)
{
    int cy = 0;

    while (tetris->nid->tetri[cy] != NULL) {
        if (check_piece(tetris->nid->tetri[cy]) == 84) {
            tetris->nid->tetri = rm_wrong_tetrimos(tetris->nid->tetri, cy);
            if (tetris->nid->tetri == NULL)
                return (84);
            cy = 0;
            continue;
        }
        cy = cy + 1;
    }
    return (0);
}