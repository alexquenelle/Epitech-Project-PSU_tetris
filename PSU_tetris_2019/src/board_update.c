/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** check_collision.c
*/

#include "my.h"

void level_up(tetris_t *tetris)
{
    static int get = 1;

    if ((tetris->igame->up % 10) == 0 && tetris->igame->up != get) {
        tetris->igame->lvl = tetris->igame->lvl + 1;
        get = get + 1;
    }
}

char **up_game_board(char **board)
{
    int cy = check_filled_line(board);
    int cx = 0;

    while (cy > 1) {
        while (board[cy][cx] != '\0') {
            board[cy][cx] = board[cy - 1][cx];
            cx = cx + 1;
        }
        cx = 0;
        cy = cy - 1;
    }
    return (board);
}

char **update_game_board(tetris_t *tetris, char **board)
{
    int cy = check_filled_line(board);
    int cx = 0;

    if (cy != 0) {
        tetris->igame->up = tetris->igame->up + 1;
        tetris->igame->score = tetris->igame->score + 10;
        board = up_game_board(board);
    }
    level_up(tetris);
    return (board);
}

char **change_tetriminos(tetris_t *tetris, char **piece)
{
    clear();
    tetris->info->opt = 1;
    piece = tetris->igame->next;
    tetris->info->col = tetris->igame->ncol;
    tetris->igame->next = get_next_piece(tetris);
    return (piece);
}