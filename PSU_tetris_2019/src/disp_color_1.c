/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** disp_color_1.c
*/

#include "my.h"

void color_zero(int cy, int x, char c)
{
    attron(COLOR_PAIR(0));
    mvprintw(cy, x, "%c", '*');
    attroff(COLOR_PAIR(0));
}

void color_one(int cy, int x, char c)
{
    attron(COLOR_PAIR(1));
    mvprintw(cy, x, "%c", '*');
    attroff(COLOR_PAIR(1));
}

void color_two(int cy, int x, char c)
{
    attron(COLOR_PAIR(2));
    mvprintw(cy, x, "%c", '*');
    attroff(COLOR_PAIR(2));
}

void color_three(int cy, int x, char c)
{
    attron(COLOR_PAIR(3));
    mvprintw(cy, x, "%c", '*');
    attroff(COLOR_PAIR(3));
}

void color_four(int cy, int x, char c)
{
    attron(COLOR_PAIR(4));
    mvprintw(cy, x, "%c", '*');
    attroff(COLOR_PAIR(4));
}