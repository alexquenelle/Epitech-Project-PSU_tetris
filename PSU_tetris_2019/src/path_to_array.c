/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** path_to_array.c
*/

#include "my.h"

char **copy_path_to_arrray(DIR *folder, char **new)
{
    struct dirent *file;
    int cy = 0;

    while (file = readdir(folder)) {
        if (file->d_name[0] != '.') {
            new[cy] = my_strdup(file->d_name);
            if (new[cy] == NULL)
                return (NULL);
            cy = cy + 1;
        }
    }
    new[cy] = NULL;
    return (new);
}

char **path_to_array(char *path, int len)
{
    char **new = NULL;
    DIR *folder = NULL;
    struct dirent *file;

    folder = opendir(path);
    if (folder == NULL)
        return (NULL);
    new = malloc(sizeof(char *) * (len + 1));
    if (new == NULL)
        return (NULL);
    if (copy_path_to_arrray(folder, new) == NULL)
        return (NULL);
    return (new);
}