/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** setup_ingame.c
*/

#include "my.h"

int check_filled_line_ret(char *str, int len)
{
    int inc = 1;
    int nbr = 0;

    while (str[inc] != '\0') {
        if (str[inc] > '0' && str[inc] < '9')
            nbr = nbr + 1;
        if (nbr == len)
            return (1);
        inc = inc + 1;
    }
    return (0);
}

int check_filled_line(char **board)
{
    int cy = 0;
    int len = my_strlen(board[0]) - 2;

    while (board[cy] != NULL) {
        if (check_filled_line_ret(board[cy], len) == 1)
            return (cy);
        cy = cy + 1;
    }
    return (0);
}