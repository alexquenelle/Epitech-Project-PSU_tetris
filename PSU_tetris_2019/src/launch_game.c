/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** launch_game.c
*/

#include "my.h"

int launch_game(tetris_t *tetris)
{
    size_t bufsize = 32;
    char *buffer = NULL;
    char **folder = NULL;
    int key = 0;

    if (get_file_name(tetris, "./tetriminos") == 84)
        return (84);
    my_printf("Press any key to start Tetris");
    getline(&buffer, &bufsize, stdin);
    if (buffer != NULL){
        if (prepare_tetris_game(tetris) == 84)
        return (84);
    }
    return (0);
}