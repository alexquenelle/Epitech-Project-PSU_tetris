/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** error_handling_debug.c
*/

#include "my.h"

int save_place_l(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp_custom("--key-left=", av[i]) == 1){
        tetris->debug->left =
        malloc(sizeof(char) * (my_strlen(av[i]) - 10));
        my_strcpy_custom(tetris->debug->left, av[i], 11);
    }
    else if (av[i + 1] != NULL) {
        tetris->debug->left =
        malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
        my_strcpy(tetris->debug->left, av[i + 1], 0);
    }
    if (my_strlen(tetris->debug->left) != 1 &&
    my_strcmp(tetris->debug->left, "left arrow") == 0)
        return (1);
    return (0);
}

int save_place_r(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp_custom("--key-right=", av[i]) == 1){
        tetris->debug->right =
        malloc(sizeof(char) * (my_strlen(av[i]) - 12));
        my_strcpy_custom(tetris->debug->right, av[i], 12);
    }
    else if (av[i + 1] != NULL) {
        tetris->debug->right =
        malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
        my_strcpy(tetris->debug->right, av[i + 1], 0);
    }
    if (my_strlen(tetris->debug->right) != 1 &&
    my_strcmp(tetris->debug->right, "right arrow") == 0)
        return (1);
    return (0);
}

int save_place_t(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp_custom("--key-turn=", av[i]) == 1){
        tetris->debug->turn =
        malloc(sizeof(char) * (my_strlen(av[i]) - 10));
        my_strcpy_custom(tetris->debug->turn, av[i], 11);
    }
    else if (av[i + 1] != NULL) {
        tetris->debug->turn =
        malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
        my_strcpy(tetris->debug->turn, av[i + 1], 0);
    }
    if (my_strlen(tetris->debug->turn) != 1 &&
    my_strcmp(tetris->debug->turn, "top arrow") == 0)
        return (1);
    return (0);
}

int save_place_d(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp_custom("--key-drop=", av[i]) == 1){
        tetris->debug->drop =
        malloc(sizeof(char) * (my_strlen(av[i]) - 10));
        my_strcpy_custom(tetris->debug->drop, av[i], 11);
    }
    else if (av[i + 1] != NULL) {
        tetris->debug->drop =
        malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
        my_strcpy(tetris->debug->drop, av[i + 1], 0);
    }
    if (my_strlen(tetris->debug->drop) != 1 &&
    my_strcmp(tetris->debug->drop, "down arrow") == 0)
        return (1);
    return (0);
}

int save_place_q(tetris_t *tetris, char **av, int i)
{
    if (my_strcmp_custom("--key-quit=", av[i]) == 1){
        tetris->debug->quit =
        malloc(sizeof(char) * (my_strlen(av[i]) - 10));
        my_strcpy_custom(tetris->debug->quit, av[i], 11);
    }
    else if (av[i + 1] != NULL) {
        tetris->debug->quit =
        malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
        my_strcpy(tetris->debug->quit, av[i + 1], 0);
    }
    if (my_strlen(tetris->debug->quit) != 1)
        return (1);
    return (0);
}