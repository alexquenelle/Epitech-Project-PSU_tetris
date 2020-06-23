/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** check_moving_1.c
*/

#include "my.h"

int proc_check_right_2(tetris_t *tetris, char c, int savey, int savex1)
{
    if (c == '*') {
        if (tetris->nid->bd[savey][savex1 + 1] > '0'
        && tetris->nid->bd[savey][savex1 + 1] < '9')
            return (1);
    }
    return (0);
}

int proc_check_right_1(tetris_t *tetris, char *str, int savey, int savex1)
{
    int inc = 0;

    while (str[inc] != '\0') {
        if (proc_check_right_2(tetris, str[inc], savey, savex1) == 1)
            return (1);
        savex1 = savex1 + 1;
        inc = inc + 1;
    }
    return (0);
}

int proc_check_right(tetris_t *tetris, char **piece, int savex1, int savey)
{
    int cy = 0;
    int cx = 0;
    int savex = savex1;

    while (piece[cy] != NULL) {
        if (proc_check_right_1(tetris, piece[cy], savey, savex1) == 1)
            return (1);
        savex1 = savex;
        cx = 0;
        cy = cy + 1;
        savey = savey + 1;
    }
    return (0);
}