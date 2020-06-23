/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** get_info.c
*/

#include "my.h"

int get_best_score(char *path)
{
    struct stat info;
    char *new = NULL;
    char **stock = NULL;
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return (-1);
    stat(path, &info);
    new = malloc(sizeof(char) * (info.st_size + 1));
    if (new == NULL)
        return (-1);
    if (read(fd, new, info.st_size) == 0)
        return (0);
    stock = malloc(sizeof(char *) * (my_strsize(new) + 1));
    piece_to_array(stock, new);
    close(fd);
    return (my_atoi(stock[0]));
}

char **get_logo(char *path)
{
    struct stat info;
    char *new = NULL;
    char **stock = NULL;
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    stat(path, &info);
    new = malloc(sizeof(char) * (info.st_size + 1));
    if (new == NULL)
        return (NULL);
    if (read(fd, new, info.st_size) == 0)
        return (NULL);
    stock = malloc(sizeof(char *) * (my_strsize(new) + 1));
    piece_to_array(stock, new);
    close(fd);
    return (stock);
}

char **upload_infos(tetris_t *tetris)
{
    char **logo = get_logo("./logo.txt");

    if (logo == NULL)
        return (NULL);
    tetris->igame->bscore = get_best_score("./score.dat");
    tetris->nid->bd = create_game_board(tetris->nid->sx, tetris->nid->sy);
    if (tetris->nid->bd == NULL)
        return (NULL);
    return (logo);
}