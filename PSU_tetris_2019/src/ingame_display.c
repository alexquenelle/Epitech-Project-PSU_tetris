/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** ingame_display.c
*/

#include "my.h"

void disp_game_board(char **board, int x, int y)
{
    int cy = 0;
    int cx = 0;
    int save = x;

    while (board[cy] != NULL) {
        while (board[cy][cx] != '\0') {
            choose_color(board[cy][cx], y, x);
            cx = cx + 1;
            x = x + 1;
        }
        x = save;
        cx = 0;
        cy = cy + 1;
        y = y + 1;
    }
}

void disp_tetri(tetris_t *tetris, char *str, int cy, int savey)
{
    int inc = 0;
    int savex1 = tetris->info->x;

    while (str[inc] != '\0') {
        if (str[inc] == '*') {
            attron(COLOR_PAIR(tetris->info->col));
            mvprintw(cy + 1 + savey, savex1, "%c", str[inc]);
            attroff(COLOR_PAIR(tetris->info->col));
        }
        inc = inc + 1;
        savex1 = savex1 + 1;
    }
}

void display_tetriminos(char **piece, tetris_t *tetris, int savex1, int savey)
{
    int cy = 0;

    while (piece[cy] != NULL) {
        disp_tetri(tetris, piece[cy], cy, savey);
        cy = cy + 1;
    }
}

int disp_handling(char **piece, tetris_t *tetris)
{
    int savex1 = tetris->info->x;
    int savex = tetris->info->x;
    int savey = tetris->info->y;
    if (check_collision(piece, tetris) == 1) {
        tetris->info->opt = 0;
        tetris->info->y = -1;
        tetris->info->x = tetris->nid->sx / 2 - my_arraysize(piece);
        copie_piece_to_board(piece, savex, savey, tetris);
        return (0);
    }
    if ((savey + my_arraysize(piece)) <= (tetris->nid->sy - 2))
        display_tetriminos(piece, tetris, tetris->info->x, tetris->info->y);
    else {
        tetris->info->opt = 0;
        tetris->info->y = -1;
        tetris->info->x = tetris->nid->sx / 2 - my_arraysize(piece);
        copie_piece_to_board(piece, savex, savey, tetris);
    }
    return (0);
}