/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** disp_color_2.c
*/

#include "my.h"

void color_five(int cy, int x, char c)
{
    attron(COLOR_PAIR(5));
    mvprintw(cy, x, "%c", '*');
    attroff(COLOR_PAIR(5));
}

void color_six(int cy, int x, char c)
{
    attron(COLOR_PAIR(6));
    mvprintw(cy, x, "%c", '*');
    attroff(COLOR_PAIR(6));
}

void color_seven(int cy, int x, char c)
{
    attron(COLOR_PAIR(7));
    mvprintw(cy, x, "%c", '*');
    attroff(COLOR_PAIR(7));
}

void not_color(int cy, int x, char c)
{
    mvprintw(cy, x, "%c", c);
}

void choose_color(char c, int cy, int x)
{
    int inc = 0;
    const char *flags = "01234567 *";
    void (*board[10])(int, int, char) = {&color_zero, &color_one, &color_two,
    &color_three, &color_four, &color_five, &color_six, &color_seven,
    &not_color, &not_color};

    while (flags[inc] != '\0')
    {
        if (flags[inc] == c)
            board[inc](cy, x, c);
        inc = inc + 1;
    }
}