/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** start_game.c
*/

#include "my.h"

void init_all_colors(void)
{
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void final_setup(tetris_t *tetris, char **piece)
{
    tetris->igame->next = get_next_piece(tetris);
    tetris->info->opt = 2;
    tetris->info->y = -1;
    tetris->info->x = tetris->nid->sx / 2 - my_arraysize(piece);
    tetris->igame->lvl = 1;
    tetris->gtm->pause = 0;
    tetris->gtm->tp = 0;
    tetris->igame->up = 1;
}

void start_game(tetris_t *tetris, char **logo)
{
    char **piece = get_piece(tetris);

    final_setup(tetris, piece);
    while (1) {
        disp_game_board(tetris->nid->bd, 0, 0);
        if (tetris->info->opt == 0)
            piece = change_tetriminos(tetris, piece);
        tetris->nid->bd = update_game_board(tetris, tetris->nid->bd);
        check_filled_line(tetris->nid->bd);
        if (tetris->igame->optnext == 1)
            display_next_tetrimino(tetris, tetris->igame->next, 9, 2);
        display_info_game(tetris, piece, tetris->nid->sx + 2);
        time_handling(tetris);
        disp_handling(piece, tetris);
        piece = key_handling(tetris, piece, my_arraysize(piece));
        disp_game_board(logo, 0, tetris->nid->sy + 1);
        refresh();
        noecho();
    }
}

int prepare_ncurses(tetris_t *tetris)
{
    int cx = 0;
    int cy = 0;
    char **logo = upload_infos(tetris);

    if (logo == NULL)
        return (84);
    initscr();
    getmaxyx(stdscr, cy, cx);
    if (cx <= tetris->nid->sx || cy <= tetris->nid->sy) {
        endwin();
        my_printf("Terminal size is too small, please resize it\n");
        return (0);
    }
    keypad(stdscr, TRUE);
    init_all_colors();
    prepare_time_handling(tetris);
    start_game(tetris, logo);
    endwin();
    return (0);
}