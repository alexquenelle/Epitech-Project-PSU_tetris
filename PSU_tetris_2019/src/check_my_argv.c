/*
** EPITECH PROJECT, 2019
** game_tetris
** File description:
** check_my_argv.c
*/

#include "my.h"

int check_argv(int ac, char **av, tetris_t *tetris)
{
    int i = 0;

    set_default_debug(tetris);
    while (i != ac){
        if (my_strcmp("-D", av[i]) == 1 || my_strcmp("--debug", av[i]) == 1){
            if (debug_mode(ac, av, tetris) == 1)
                return (1);
            fill_debug(tetris);
            launch_game(tetris);
        }
        else if (my_strcmp("--help", av[i]) == 1){
            get_help(av);
            return (0);
        }
        i = i + 1;
    }
    return (1);
}

int set_default_debug(tetris_t *tetris)
{
    tetris->debug->left = "left arrow";
    tetris->debug->right = "right arrow";
    tetris->debug->turn = "top arrow";
    tetris->debug->drop = "down arrow";
    tetris->debug->quit = "q";
    tetris->debug->pause = "space bar";
    tetris->debug->next = "Yes";
    tetris->debug->level = "1";
    tetris->debug->size_y = "20";
    tetris->debug->size_x = "10";
}

int debug_mode(int ac, char **av, tetris_t *tetris)
{
    int i = 0;

    while (i != ac){
        if (check_next_av(av, i) == 0 && my_strcmp(av[i], "--debug") == 0
        && my_strcmp(av[i], "-D") == 0){
            if (flag_left(tetris, av, i) == 1 ||
            flag_right(tetris, av, i) == 1 || flag_turn(tetris, av, i) == 1
            || flag_drop(tetris, av, i) == 1 || flag_quit(tetris, av, i) == 1
            || flag_pause(tetris, av, i) == 1 || flag_next(tetris, av, i) == 1
            || flag_level(tetris, av, i) == 1 ||
            flag_map_size(tetris, av, i) == 1)
                return (1);
        }
        else if (check_next_av(av, i) == 1)
            return (1);
        i = i + 1;
    }
    return (0);
}

int check_next_av(char **av, int i)
{
    if (i >= 2 && av[i][0] == '-' && my_strlen(av[i]) == 2
    && my_strcmp(av[i], "-D") == 0){
        if (my_strcmp(av[i + 1], "-l") == 1 || my_strcmp(av[i + 1], "-r") == 1
        || my_strcmp(av[i + 1], "-t") == 1 || my_strcmp(av[i + 1], "-d") == 1
        || my_strcmp(av[i + 1], "-q") == 1 || my_strcmp(av[i + 1], "-p") == 1
        || my_strcmp(av[i + 1], "-w") == 1 || my_strcmp(av[i + 1], "-L") == 1
        || av[i + 1] == NULL){
            return (1);
        }
    }
    return (0);
}

int fill_debug(tetris_t *tetris)
{
    my_printf("*** DEBUG MODE ***\n");
    my_printf("Key Left :  %s\n", tetris->debug->left);
    my_printf("Key Right :  %s\n", tetris->debug->right);
    my_printf("Key Turn :  %s\n", tetris->debug->turn);
    my_printf("Key Drop :  %s\n", tetris->debug->drop);
    my_printf("Key Quit :  %s\n", tetris->debug->quit);
    my_printf("Key Pause :  %s\n", tetris->debug->pause);
    my_printf("Next :  %s\n", tetris->debug->next);
    my_printf("Level :  %s\n", tetris->debug->level);
    my_printf("Size :  %s", tetris->debug->size_y);
    my_printf("*");
    my_printf("%s\n", tetris->debug->size_x);
    my_printf("Tetriminos : %d\n", get_nbr_tetriminos("./tetriminos"));
}