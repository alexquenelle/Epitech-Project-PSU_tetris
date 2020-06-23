/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** print_file.c
*/

#include "my.h"

void print_file_name(char **folder, char *path, tetris_t *tetris)
{
    int cy = 0;

    while (folder[cy] != NULL)
    {
        my_printf("Tetriminos :  Name ");
        write(1, folder[cy], my_strlen_custom(folder[cy]));
        if (print_tetriminos(folder[cy], path, tetris) == 1)
            my_printf(" : Error\n");
        cy = cy + 1;
    }
}

int rd(char *path, tetris_t *tetris)
{
    struct stat info;
    int fd = open(path, O_RDONLY);
    char **file_array = NULL;

    if (fd == -1)
        return (84);
    stat(path, &info);
    char *file = malloc(sizeof(char) * (info.st_size + 1));
    if (read(fd, file, info.st_size) == 0)
        return (1);
    file[info.st_size] = '\0';
    file_array = tetriminos_to_array(path);
    info_tetriminos(file_array, tetris);
    close(fd);
    return (0);
}

int info_tetriminos(char **file_array, tetris_t *tetris)
{
    int y = 1;

    if (my_str_isnum(file_array[0]) == 1
    && file_array[0][1] == ' ' && file_array[0][3] == ' '){
        my_printf(" : Size : %c*%c", file_array[0][0], file_array[0][2]);
        my_printf(" :  Color %c :\n", file_array[0][4]);
        while (file_array[y] != NULL) {
            my_printf("%s\n", file_array[y]);
            y = y + 1;
        }
    } else {
        my_printf(" : Error\n");
    }
}

int print_tetriminos(char *folder, char *path, tetris_t *tetris)
{
    int cy = 0;
    char *new = NULL;

    new = my_strcat_add(path, folder, '/');
    if (rd(new, tetris) == 1)
        return (1);
}

int get_file_name(tetris_t *tetris, char *path)
{
    char **folder = NULL;
    int nbr = get_nbr_tetriminos(path);

    if (nbr == 0 || nbr == -1)
        return (84);
    folder = path_to_array(path, nbr);
    if (folder == NULL)
        return (84);
    change_order(folder, my_arraysize(folder));
    if (folder == NULL)
        return (84);
    print_file_name(folder, path, tetris);
    return (0);
}