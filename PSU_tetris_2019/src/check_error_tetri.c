/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** error_handlint_tetri.c
*/

#include "my.h"

int check_tetri_height(tetris_t *tetris)
{
    int cy = 0;
    int len = 0;

    while (tetris->nid->tetri[cy] != NULL) {
        tetris->info->height = tetris->nid->tetri[cy][0][2] - 48;
        len = my_arraysize(tetris->nid->tetri[cy]);
        if (len != (tetris->info->height + 1)) {
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

int check_tetri_width(tetris_t *tetris)
{
    int cy = 0;
    int big = 0;

    while (tetris->nid->tetri[cy] != NULL) {
        tetris->info->widht = tetris->nid->tetri[cy][0][0] - 48;
        big = find_bigger_line(tetris->nid->tetri[cy], 1);
        if (big != (tetris->info->widht)) {
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

int check_all_my_tetriminos(tetris_t *tetris)
{
    if (check_all_pieces(tetris) == 84)
        return (84);
    if (check_tetri_first_line(tetris) == 84)
        return (84);
    if (check_tetri_height(tetris) == 84)
        return (84);
    if (check_tetri_width(tetris) == 84)
        return (84);
    return (0);
}