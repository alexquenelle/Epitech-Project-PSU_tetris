/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** check_error_tetri_2.c
*/

#include "my.h"

int check_letters_placement(char **board)
{
    if (board[0][0] == ' ' || board[0][2] == ' ' || board[0][4] == ' ')
        return (84);
    if (board[0][4] < '0' || board[0][4] > '7')
        return (84);
    return (0);
}

int check_first_line(char **board)
{
    int cx = 0;

    if (my_strlen(board[0]) != 5)
        return (84);

    while (board[0][cx] != '\0') {
        if (board[0][cx] != ' ' && (board[0][cx] < '0' || board[0][cx] > '9'))
            return (84);
        cx = cx + 1;
    }
    if (check_letters_placement(board) == 84)
        return (84);
    return (0);
}

int check_tetri_first_line(tetris_t *tetris)
{
    int cy = 0;

    while (tetris->nid->tetri[cy] != NULL) {
        if (check_first_line(tetris->nid->tetri[cy]) == 84) {
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