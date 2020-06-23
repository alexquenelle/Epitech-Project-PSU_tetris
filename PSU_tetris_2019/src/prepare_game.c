/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** prepare_game.c
*/

#include "my.h"

char *open_path(char *path)
{
    struct stat info;
    int fd = open(path, O_RDONLY);
    char *stock = NULL;

    if (fd == -1 || stat(path, &info) == -1)
        return (NULL);
    stock = malloc(sizeof(char) * (info.st_size + 1));
    if (stock == NULL)
        return (NULL);
    read(fd, stock, info.st_size);
    stock[info.st_size] = '\0';
    return (stock);
}

int upload_tetriminos(tetris_t *tetris, int nbr)
{
    int cy = 0;

    tetris->nid->path = get_tetriminos_path("./tetriminos", nbr);
    if (tetris->nid->path == NULL) {
        return (84);
    }
    tetris->nid->tetri = malloc(sizeof(char **) * (nbr + 1));
    if (tetris->nid->tetri == NULL)
        return (84);
    while (nbr > 0) {
        tetris->nid->tetri[cy] = tetriminos_to_array(tetris->nid->path[cy]);
        if (tetris->nid->tetri[cy] == NULL)
            return (84);
        cy = cy + 1;
        nbr = nbr - 1;
    }
    tetris->nid->tetri[cy] = NULL;
    return (0);
}

int prepare_tetris_game(tetris_t *tetris)
{
    int nbr = 0;

    tetris->nid = malloc(sizeof(nid_t));
    tetris->gtm = malloc(sizeof(gtm_t));
    tetris->igame = malloc(sizeof(igame_t));
    tetris->info = malloc(sizeof(info_t));
    prepare_default_keys(tetris);
    if (dbg_pres(tetris, tetris->debug->nbr, tetris->debug->args) == 1)
        change_default_keys(tetris);
    nbr = get_nbr_tetriminos("./tetriminos");
    if (nbr == 0 || nbr == -1)
        return (84);
    if (last_setup(tetris, nbr) == 84)
        return (84);
    if (prepare_ncurses(tetris) == 84)
        return (84);
    return (0);
}