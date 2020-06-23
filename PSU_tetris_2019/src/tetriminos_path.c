/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** tetriminos_path.c
*/

#include "my.h"

char **cpy_tetriminos_path(DIR *folder, char *path, char **all_path)
{
    int cy = 0;
    struct dirent *readed;

    while ((readed = readdir(folder))) {
        if (readed->d_name[0] != '.') {
            all_path[cy] = my_strcat_add(path, readed->d_name, '/');
            if (all_path[cy] == NULL)
                return (NULL);
            cy = cy + 1;
        }
    }
    all_path[cy] = NULL;
    return (all_path);
}

char **get_tetriminos_path(char *path, int nbr)
{
    int cy = 0;
    char **all_path = NULL;
    DIR *folder = NULL;
    folder = opendir(path);

    if (folder == NULL)
        return (NULL);
    all_path = malloc(sizeof(char *) * (nbr + 1));
    if (all_path == NULL)
        return (NULL);
    if (cpy_tetriminos_path(folder, path, all_path) == NULL)
        return (NULL);
    closedir(folder);
    return (all_path);
}