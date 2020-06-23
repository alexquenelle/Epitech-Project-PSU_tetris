/*
** EPITECH PROJECT, 2019
** new_navy
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    tetris_t *tetris = NULL;

    if (*env == NULL)
        return (84);
    tetris = malloc(sizeof(tetris_t));
    tetris->debug = malloc(sizeof(debug_t));
    if (tetris == NULL || tetris->debug == NULL)
        return (84);
    srand(time(NULL));
    tetris->debug->nbr = ac;
    tetris->debug->args = cpy_array(av, 0, 0);
    if (check_argv(ac, av, tetris) == 1 && ac > 1)
        return (84);
    if (ac == 1) {
        if (prepare_tetris_game(tetris) == 84)
            return (84);
    }
    return (0);
}