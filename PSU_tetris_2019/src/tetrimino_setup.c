/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** tetrimino_setup.c
*/

#include "my.h"

int get_delete_info(tetris_t *tetris)
{
    int cy = 0;
    int add = 0;
    int len = my_arraylistlen(tetris->nid->tetri);

    tetris->nid->info = malloc(sizeof(int) * (len + 1));
    if (tetris->nid->info == NULL)
        return (84);
    while (tetris->nid->tetri[cy] != NULL) {
        tetris->nid->info[add] = tetris->nid->tetri[cy][0][4] - 48;
        tetris->nid->tetri[cy] = cpy_array(tetris->nid->tetri[cy], 1, 1);
        if (tetris->nid->tetri[cy] == NULL)
            return (84);
        add = add + 1;
        cy = cy + 1;
    }
    tetris->nid->info[add] = -1;
    return (0);
}

int last_setup(tetris_t *tetris, int nbr)
{
    if (upload_tetriminos(tetris, nbr) == 84)
        return (84);
    if (check_all_my_tetriminos(tetris) == 84)
        return (84);
    if (get_delete_info(tetris) == 84)
        return (84);
    return (0);
}