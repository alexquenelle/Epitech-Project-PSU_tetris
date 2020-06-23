/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** check_moving.c
*/

#include "my.h"

int proc_check_left_2(tetris_t *tetris, char c, int savey, int savex1)
{
    if (c == '*') {
        if (tetris->nid->bd[savey][savex1 - 1] > '0'
        && tetris->nid->bd[savey][savex1 - 1] < '9')
            return (1);
    }
    return (0);
}

int proc_check_left_1(tetris_t *tetris, char *str, int savey, int savex1)
{
    int inc = 0;

    while (str[inc] != '\0') {
        if (proc_check_left_2(tetris, str[inc], savey, savex1) == 1)
            return (1);
        savex1 = savex1 + 1;
        inc = inc + 1;
    }
    return (0);
}

int proc_check_left(tetris_t *tetris, char **piece, int savex1, int savey)
{
    int cy = 0;

    while (piece[cy] != NULL) {
        if (proc_check_left_1(tetris, piece[cy], savey, savex1) == 1)
            return (1);
        cy = cy + 1;
        savey = savey + 1;
    }
    return (0);
}

int check_left(tetris_t *tetris, char **piece)
{
    int cy = 0;
    int cx = 0;
    int savex1 = tetris->info->x;
    int savey = tetris->info->y;

    if (tetris->info->y > 1 && tetris->info->y < 20) {
        if (proc_check_left(tetris, piece, savex1, savey) == 1)
            return (1);
    }
    return (0);
}

int check_right(tetris_t *tetris, char **piece)
{
    int cy = 0;
    int cx = 0;
    int savex1 = tetris->info->x;
    int savey = tetris->info->y;

    if (tetris->info->y > 1 && tetris->info->y < 20) {
        if (proc_check_right(tetris, piece, savex1, savey) == 1)
            return (1);
    }
    return (0);
}