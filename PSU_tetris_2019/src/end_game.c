/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** end_game.c
*/

#include "my.h"

void stock_score(char *path, int score)
{
    int fd = open(path, O_WRONLY);
    char *copy = my_convert(score);
    write(fd, copy, my_strlen(copy));
    write(fd, "\n", 1);
    close(fd);
}

void end_handling(tetris_t *tetris)
{
    endwin();
    if (tetris->igame->score > tetris->igame->bscore) {
        my_printf("You beat the previous score. Congratulations !\n");
        my_printf("Your score is: %d\n", tetris->igame->score);
        stock_score("./score.dat", tetris->igame->score);
    }
    else
        my_printf("Game Finished, you score is: %d\n", tetris->igame->score);
    exit (0);
}