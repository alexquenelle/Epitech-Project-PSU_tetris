/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** display_next.c
*/

#include "my.h"

void disp_next_tetri(tetris_t *tetris, char *str, int py)
{
    int inc = 0;
    int px = 2;

    while (str[inc] != '\0') {
        if (str[inc] == '*') {
            attron(COLOR_PAIR(tetris->igame->ncol));
            mvprintw(py, tetris->nid->sx + 2 + px, "%c", str[inc]);
            attroff(COLOR_PAIR(tetris->igame->ncol));
        }
        else
            mvprintw(py, tetris->nid->sx + 2 + px, "%c", str[inc]);
        inc = inc + 1;
        px = px +  1;
    }
}

void display_next_tetrimino(tetris_t *tetris, char **next, int py, int px)
{
    int cy = 0;

    display_rect_next(tetris, next);
    while (next[cy] != NULL) {
        disp_next_tetri(tetris, next[cy], py);
        cy = cy + 1;
        py = py + 1;
    }
}