/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** my_board_display.c
*/

#include "my.h"

void display_board(char **board)
{
    int cy = 0;

    while (board[cy] != NULL) {
        my_printf("%s\n", board[cy]);
        cy = cy + 1;
    }
}

void display_my_3d(char ***stock)
{
    int cy = 0;

    while (stock[cy] != NULL)
    {
        display_board(stock[cy]);
        if (stock[cy + 1] != NULL)
            my_putchar('\n');
        cy = cy + 1;
    }
}