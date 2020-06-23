/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** ingame_time.c
*/

#include "my.h"

void prepare_time_handling(tetris_t *tetris)
{
    tetris->gtm->go = time(NULL);
    tetris->gtm->min = 0;
    tetris->gtm->sec = 0;
    tetris->gtm->fsec = 0.00;
    tetris->gtm->fsc = 1.00;
    tetris->gtm->tmin = 1;
    tetris->igame->score = 0;
}

void updating_time(tetris_t *tetris)
{
    float add = 0.00;
    static int lvl = 1;
    tetris->gtm->min = tetris->gtm->curr / 60;
    tetris->gtm->sec = tetris->gtm->curr % 60;
    tetris->gtm->fsec = tetris->gtm->curr % 60;
    tetris->gtm->curr = time(NULL) - tetris->gtm->go - tetris->gtm->tp;

    if (tetris->igame->lvl == lvl) {
        add = add + (tetris->igame->lvl / 10);
        lvl = lvl + 1;
    }
    if (tetris->gtm->fsec == tetris->gtm->fsc) {
        tetris->info->y = tetris->info->y + 1;
        tetris->gtm->fsc = tetris->gtm->fsc + 1 - add;
    } else if (tetris->gtm->fsec == 0
    && tetris->gtm->min == tetris->gtm->tmin) {
        tetris->gtm->tmin = tetris->gtm->tmin + 1;
        tetris->gtm->fsc = 0;
    }
}

void time_handling(tetris_t *tetris)
{
    if (tetris->gtm->pause == 2)
        tetris->gtm->pause = 0;
    if (tetris->gtm->pause == 0)
        updating_time(tetris);
    if (tetris->gtm->pause == 1)
        tetris->gtm->tp = time(NULL) - tetris->gtm->curr - tetris->gtm->go;
}