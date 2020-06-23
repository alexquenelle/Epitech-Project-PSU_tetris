/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** displa_info.c
*/

#include "my.h"

void display_info_game(tetris_t *tetris, char **piece, int pos)
{
    if ((check_collision(piece, tetris) == 1) && tetris->info->y <= 0)
        end_handling(tetris);
    mvprintw(1, pos, "Best  -> %d", tetris->igame->bscore);
    mvprintw(2, pos, "Score -> %d", tetris->igame->score);
    mvprintw(3, pos, "Time  -> %d:%02d", tetris->gtm->min, tetris->gtm->sec);
    mvprintw(4, pos, "Level -> %d", tetris->igame->lvl);
}

void disp_top_bot_next(tetris_t *tetris, char **next, int height, int add)
{
    int cx = 0;
    int inc = 0;
    int lim = 4;
    int nx = tetris->nid->sx + 2;

    while (next[0][cx] != '\0') {
        mvprintw(7 + add, nx + cx, "*");
        cx = cx + 1;
    }
    while (lim > 0) {
        mvprintw(7 + add, nx + cx + inc, "*");
        inc = inc + 1;
        lim = lim - 1;
    }
}

void disp_r_l_next(tetris_t *tetris, char **next, int width, int add)
{
    int cy = 0;
    int dy = 8;
    int lim = 3;
    int inc = 0;

    while (next[cy] != NULL) {
        mvprintw(dy, tetris->nid->sx + add, "*");
        dy = dy + 1;
        cy = cy + 1;
    }
    while (lim > 0) {
        mvprintw(dy + inc, tetris->nid->sx + add, "*");
        inc = inc + 1;
        lim = lim - 1;
    }
}

void display_rect_next(tetris_t *tetris, char **next)
{
    int width = my_strlen(next[0]);
    int height = my_arraysize(next);

    mvprintw(6, tetris->nid->sx + 2, "Next tetriminos is:");
    disp_top_bot_next(tetris, next, height, 0);
    disp_top_bot_next(tetris, next, height, height + 3);
    disp_r_l_next(tetris, next, width, 2);
    disp_r_l_next(tetris, next, width, width + 5);
}