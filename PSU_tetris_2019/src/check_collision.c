/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** check_collision.c
*/

#include "my.h"

int touched_or_not(tetris_t *tetris, int savey, int savex1)
{
    if (tetris->nid->bd[savey + 1][savex1] > '0' &&
    tetris->nid->bd[savey + 1][savex1] < '9' && savey != 0) {
        tetris->igame->score = tetris->igame->score + 5;
        return (1);
    }
    else if (tetris->nid->bd[savey + 1][savex1] > '0' &&
    tetris->nid->bd[savey + 1][savex1] < '9' && savey == 0)
        end_handling(tetris);
    return (0);
}

int check_collision_ret(tetris_t *tetris , char *str, int savey, int savex1)
{
    int inc = 0;

    while (str[inc] != '\0') {
        if (str[inc] == '*') {
            if (touched_or_not(tetris, savey, savex1) == 1)
                return (1);
        }
        inc = inc + 1;
        savex1 = savex1 + 1;
    }
    return (0);
}

int check_collision(char **piece, tetris_t *tetris)
{
    int cy = 0;
    int savex1 = tetris->info->x;
    int savey = tetris->info->y;

    while (piece[cy] != NULL) {
        if (check_collision_ret(tetris, piece[cy], savey, savex1) == 1)
            return (1);
        savey = savey + 1;
        cy = cy + 1;
    }
    return (0);
}