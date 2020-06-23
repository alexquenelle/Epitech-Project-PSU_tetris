/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** error_handling_debug_bis.c
*/

#include "my.h"

int save_place_p(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp_custom("--key-pause=", av[i]) == 1){
        tetris->debug->pause =
        malloc(sizeof(char) * (my_strlen(av[i]) - 12));
        my_strcpy_custom(tetris->debug->pause, av[i], 12);
    }
    else if (av[i + 1] != NULL) {
        tetris->debug->pause =
        malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
        my_strcpy(tetris->debug->pause, av[i + 1], 0);
    }
    if (my_strlen(tetris->debug->pause) != 1 &&
    my_strcmp(tetris->debug->pause, "space bar") == 0)
        return (1);
    return (0);
}

int save_place_w(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp_custom("--without-next=", av[i]) == 1){
        tetris->debug->next =
        malloc(sizeof(char) * (my_strlen(av[i]) - 15));
        my_strcpy_custom(tetris->debug->next, av[i], 15);
    }
    else if (av[i + 1] != NULL) {
    tetris->debug->next =
    malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
    my_strcpy(tetris->debug->next, av[i + 1], 0);
    }
    if (my_strcmp(tetris->debug->next, "Yes") == 0 &&
    my_strcmp(tetris->debug->next, "No") == 0)
        return (1);
    return (0);
}

int save_place_level(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp_custom("--level=", av[i]) == 1){
        tetris->debug->level =
        malloc(sizeof(char) * (my_strlen(av[i]) - 8));
        my_strcpy_custom(tetris->debug->level, av[i], 8);
    }
    else if (av[i + 1] != NULL) {
        tetris->debug->level =
        malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
        my_strcpy(tetris->debug->level, av[i + 1], 0);
    }
    if (my_str_isnum(tetris->debug->level) == 0 ||
    my_atoi(tetris->debug->level) > 10 ||
    my_atoi(tetris->debug->level) < 0)
        return (1);
    return (0);
}