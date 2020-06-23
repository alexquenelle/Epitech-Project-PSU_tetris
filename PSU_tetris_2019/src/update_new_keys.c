/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** update_new_keys.c
*/

#include "my.h"

void prepare_default_keys(tetris_t *tetris)
{
    tetris->gkey = malloc(sizeof(gkey_t));
    tetris->gkey->lvl = 1;

    tetris->gkey->left = KEY_LEFT;
    tetris->gkey->right = KEY_RIGHT;
    tetris->gkey->turn = KEY_UP;
    tetris->gkey->drop = KEY_DOWN;

    tetris->gkey->quit = 112;
    tetris->gkey->pause = 32;

    tetris->nid->sx = 20;
    tetris->nid->sy = 10;
    tetris->gkey->row = 20;
    tetris->gkey->col = 10;
    tetris->igame->optnext = 1;
}

void change_moving_keys(tetris_t *tetris)
{
    int new = 0;

    new = tetris->debug->right[0];
    if (new != tetris->gkey->right &&
    game_cmp("right arrow", tetris->debug->right) != 0)
        tetris->gkey->right = new;
    new = tetris->debug->turn[0];
    if (new != tetris->gkey->turn &&
    game_cmp("top arrow", tetris->debug->turn) != 0)
        tetris->gkey->turn = new;
    new = tetris->debug->drop[0];
    if (new != tetris->gkey->drop &&
    game_cmp("down arrow", tetris->debug->drop) != 0)
        tetris->gkey->drop = new;
}

void change_remaining_keys(tetris_t *tetris)
{
    int new = 0;

    new = tetris->debug->quit[0];
    if (new != tetris->gkey->quit &&
    game_cmp("q", tetris->debug->quit) != 0)
        tetris->gkey->quit = new;
    new = tetris->debug->pause[0];
    if (new != tetris->gkey->pause &&
    game_cmp("space bar", tetris->debug->pause) != 0)
        tetris->gkey->pause = new;
    if (game_cmp(tetris->debug->next, "Yes") != 0)
        tetris->igame->optnext = 0;
}

void change_default_keys(tetris_t *tetris)
{
    int new = 0;

    new = tetris->debug->left[0];
    if (new != tetris->gkey->left &&
    game_cmp("left arrow", tetris->debug->left) != 0)
        tetris->gkey->left = new;
    change_moving_keys(tetris);
    change_remaining_keys(tetris);
    new = my_atoi(tetris->debug->size_y);
    if (new != 10)
        tetris->nid->sx = new;
    new = my_atoi(tetris->debug->size_x);
    if (new != 20)
        tetris->nid->sy = new;
}

int dbg_pres(tetris_t *tetris, int ac, char **av)
{
    int inc = 1;

    while (inc < ac) {
        if (game_cmp("-D", av[inc]) == 0)
            return (1);
        if (game_cmp("--debug", av[inc]) == 0)
            return (1);
        inc = inc + 1;
    }
    return (0);
}