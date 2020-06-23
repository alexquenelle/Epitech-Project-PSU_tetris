/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** choose_piece.c
*/

#include "my.h"

int choose_piece(tetris_t *tetris)
{
    int len = my_arraylistlen(tetris->nid->tetri);
    int snd = rand() % len;
    return (snd);
}

char **get_piece(tetris_t *tetris)
{
    int piece = choose_piece(tetris);
    int len = my_arraysize(tetris->nid->tetri[piece]);
    char **new = malloc(sizeof(char *) * (len + 1));

    if (new == NULL)
        return (NULL);
    new = cpy_array(tetris->nid->tetri[piece], 0, 0);
    tetris->info->col = tetris->nid->info[piece];
    if (new == NULL)
        return (NULL);
    return (new);
}

char **get_next_piece(tetris_t *tetris)
{
    int piece = choose_piece(tetris);
    int len = my_arraysize(tetris->nid->tetri[piece]);
    char **new = malloc(sizeof(char *) * (len + 1));

    if (new == NULL)
        return (NULL);
    new = cpy_array(tetris->nid->tetri[piece], 0, 0);
    tetris->igame->ncol = tetris->nid->info[piece];
    if (new == NULL)
        return (NULL);
    return (new);
}