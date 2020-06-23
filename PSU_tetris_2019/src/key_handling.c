/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** key_handling.c
*/

#include "my.h"

void moving_piece(tetris_t *tetris, char **piece)
{
    int len = 0;

    if (tetris->nid->key == tetris->gkey->drop)
        tetris->info->y = tetris->info->y + 1;
    if (tetris->nid->key == tetris->gkey->left && tetris->info->x > 1) {
        if (check_left(tetris, piece) != 1)
            tetris->info->x = tetris->info->x - 1;
    }
    len = find_bigger_line(piece, 0);
    if (tetris->nid->key == tetris->gkey->right &&
    tetris->info->x < tetris->nid->sx - len + 1 - 2) {
        if (check_right(tetris, piece) != 1)
            tetris->info->x = tetris->info->x + 1;
    }
}

int key_pause(tetris_t *tetris)
{
    if (tetris->nid->key == tetris->gkey->pause
    && tetris->gtm->pause == 0) {
        tetris->gtm->pause = 1;
        return (0);
    }
    if (tetris->nid->key == tetris->gkey->pause
    && tetris->gtm->pause == 1)
        tetris->gtm->pause = 2;
    return (0);
}

char **key_handling(tetris_t *tetris, char **piece, int size)
{
    timeout(0);
    tetris->nid->key = getch();
    moving_piece(tetris, piece);
    if (tetris->nid->key == tetris->gkey->quit)
        end_handling(tetris);
    if (tetris->nid->key == tetris->gkey->turn)
        piece = rotate_me(piece, size - 1, find_bigger_line(piece, 0));
    key_pause(tetris);
    return (piece);
}