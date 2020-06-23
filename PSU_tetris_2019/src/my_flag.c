/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** check_my_argv_bis.c
*/

#include "my.h"

int flag_left(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp("-l", av[i]) == 1 ||
    my_strcmp_custom("--key-left=", av[i]) == 1){
        if (save_place_l(tetris, av, i) == 1)
            return (1);
    }
    return (0);
}

int flag_right(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp("-r", av[i]) == 1 ||
    my_strcmp_custom("--key-right=", av[i]) == 1){
        if (save_place_r(tetris, av, i) == 1)
            return (1);
    }
    return (0);
}

int flag_turn(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp("-t", av[i]) == 1 ||
    my_strcmp_custom("--key-turn=", av[i]) == 1){
        if (save_place_t(tetris, av, i) == 1)
            return (1);
    }
    return (0);
}

int flag_drop(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp("-d", av[i]) == 1 ||
    my_strcmp_custom("--key-drop=", av[i]) == 1){
        if (save_place_d(tetris, av, i) == 1)
            return (1);
    }
    return (0);
}

int flag_quit(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp("-q", av[i]) == 1 ||
    my_strcmp_custom("--key-quit=", av[i]) == 1){
        if (save_place_q(tetris, av, i) == 1)
            return (1);
    }
    return (0);
}
