/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** my_flag_bis.c
*/

#include "my.h"

int flag_pause(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp("-p", av[i]) == 1 ||
    my_strcmp_custom("--key-pause=", av[i]) == 1){
        if (save_place_p(tetris, av, i) == 1)
            return (1);
    }
    return (0);
}

int flag_next(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp("-w", av[i]) == 1 ||
    my_strcmp_custom("--without-next=", av[i]) == 1){
        if (save_place_w(tetris, av, i) == 1)
            return (1);
    }
    return (0);
}

int flag_level(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp("-L", av[i]) == 1 ||
    my_strcmp_custom("--level=", av[i]) == 1){
        if (save_place_level(tetris, av, i) == 1)
            return (1);
    }
    return (0);
}

int flag_map_size(tetris_t *tetris, char **av, int i)
{
    int j = 0;

    if (my_strcmp_custom("--map-size=", av[i]) == 1){
        tetris->debug->size_y = malloc(sizeof(char) * (my_strlen(av[i]) - 10));
        tetris->debug->size_x = malloc(sizeof(char) * (my_strlen(av[i]) - 10));
        my_strcpy_custom(tetris->debug->size_y, av[i], 11);
        my_strcpy_custom(tetris->debug->size_x, av[i],
        12 + my_strlen(tetris->debug->size_y));
    }
    if (my_str_isnum(tetris->debug->size_y) == 0 ||
    my_str_isnum(tetris->debug->size_x) == 0)
        return (1);
    return (0);
}