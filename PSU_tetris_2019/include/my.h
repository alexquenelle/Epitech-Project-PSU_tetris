/*
** EPITECH PROJECT, 2019
** new_navy
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <ncurses.h>
#include <time.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

typedef struct debug_s
{
    int nbr;
    char **args;
    char *left;
    char *right;
    char *turn;
    char *drop;
    char *quit;
    char *pause;
    char *next;
    char *level;
    char *size_y;
    char *size_x;
    char *map_color;
} debug_t;

typedef struct nid_s
{
    char **path;
    char ***tetri;
    char **bd;
    int *info;
    int key;
    int sx;
    int sy;
} nid_t;

typedef struct gtm_s
{
    int min;
    int sec;
    float fsec;
    float fsc;
    int tmin;
    int pause;
    time_t go;
    time_t curr;
    time_t tp;
} gtm_t;

typedef struct igame_s
{
    int score;
    int bscore;
    int lvl;
    int up;

    int ncol;
    char **next;
    int optnext;
} igame_t;

typedef struct info_s
{
    int y;
    int x;
    int opt;
    int widht;
    int height;
    int col;
} info_t;

typedef struct gkey_s
{
    int lvl;
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
    int row;
    int col;
    int next;
} gkey_t;

typedef struct tetris_s
{
    debug_t *debug;
    nid_t *nid;
    gtm_t *gtm;
    igame_t *igame;
    info_t *info;
    gkey_t * gkey;
} tetris_t;

tetris_t *create_tetris_struct(void);

void opt_char(va_list ap);
void opt_str(va_list ap);
void opt_dec(va_list ap);
void my_printf(char *str, ...);

void my_putchar(char c);
void my_putstr(char *str);
void my_put_nbr(int nb);
int my_atoi(char *str);

void display_board(char **board);
void display_my_3d(char ***stock);

void get_help(char **av);
int my_strcmp(char *str1, char *str2);
int game_cmp(char *str1, char *str2);

int my_strlen(char *str);
int get_nbr_tetriminos(char *path);
int my_strsize(char *str);
int my_returnlen(char *str);

char *my_strcat_add(char *bfr, char *last, char add);
char *my_strcpy(char *new, char *src, int inc);

char **cpy_tetriminos_path(DIR *folder, char *path, char **all_path);
char **get_tetriminos_path(char *path, int nbr);
char **tetriminos_to_array(char *path);
char **piece_to_array(char **tetri, char *piece);
char *cpy_piece_to_array(char *piece, int inc, int len);

int prepare_tetris_game(tetris_t *tetris);
char *open_path(char *path);
int upload_tetriminos(tetris_t *tetris, int nbr);

char *cpy_start_end_line(int x);
char *cpy_line_to_board(int x, int y);
char **create_rest(char **board, int x, int y);
char **create_game_board(int x, int y);

char **rotate_me(char **piece, int size, int len);
char *cpy_rotate_me(char **piece, int size, int inc);
int find_bigger_line(char **board, int inc);
int my_arraysize(char **board);

char ***rm_wrong_tetrimos(char ***board, int cy);
int my_arraylistlen(char ***board);
char **cpy_array(char **board, int inc, int min);
char *my_strdup(char *copy);

int check_all_my_tetriminos(tetris_t *tetris);
int check_tetri_height(tetris_t *tetris);
int check_tetri_width(tetris_t *tetris);

int check_letters_placement(char **board);
int check_first_line(char **board);
int check_tetri_first_line(tetris_t *tetris);

int get_delete_info(tetris_t *tetris);
int last_setup(tetris_t *tetris, int nbr);

void color_zero(int cy, int x, char c);
void color_one(int cy, int x, char c);
void color_two(int cy, int x, char c);
void color_three(int cy, int x, char c);
void color_four(int cy, int x, char c);

void color_five(int cy, int x, char c);
void color_six(int cy, int x, char c);
void color_seven(int cy, int x, char c);
void not_color(int cy, int x, char c);
void choose_color(char c, int cy, int x);

int choose_piece(tetris_t *tetris);
char **get_piece(tetris_t *tetris);
void start_game(tetris_t *tetris, char **logo);

int get_best_score(char *path);
char **get_logo(char *path);
char **upload_infos(tetris_t *tetris);

void display_next_tetrimino(tetris_t *tetris, char **next, int py, int px);
void display_rect_next(tetris_t *tetris, char **next);
void disp_r_l_next(tetris_t *tetris, char **next, int width, int add);
void disp_top_bot_next(tetris_t *tetris, char **next, int height, int add);
void display_info_game(tetris_t *tetris, char **piece, int pos);

void prepare_time_handling(tetris_t *tetris);
void updating_time(tetris_t *tetris);
void time_handling(tetris_t *tetris);

void moving_piece(tetris_t *tetris, char **piece);
int key_pause(tetris_t *tetris);
char **key_handling(tetris_t *tetris, char **piece, int size);

int check_right(tetris_t *tetris, char **piece);
int proc_check_right(tetris_t *tetris, char **piece, int savex1, int savey);
int check_left(tetris_t *tetris, char **piece);
int proc_check_left(tetris_t *tetris, char **piece, int savex1, int savey);

int disp_handling(char **piece, tetris_t *tetris);
void display_tetriminos(char **piece, tetris_t *tetris, int savex1, int savey);
void disp_game_board(char **board, int x, int y);

void stock_score(char *path, int score);
void end_handling(tetris_t *tetris);

char **copie_piece_to_board(char **piece, int x, int y, tetris_t *tetris);
char **update_game_board(tetris_t *tetris, char **board);
char **change_tetriminos(tetris_t *tetris, char **piece);

int touched_or_not(tetris_t *tetris, int savey, int savex1);
int check_collision(char **piece, tetris_t *tetris);
int check_filled_line(char **board);

int my_intlen(int nbr);
char *my_convert(int nbr);
int prepare_ncurses(tetris_t *tetris);
char **get_next_piece(tetris_t *tetris);

void prepare_default_keys(tetris_t *tetris);
void change_moving_keys(tetris_t *tetris);
void change_remaining_keys(tetris_t *tetris);
void change_default_keys(tetris_t *tetris);
int dbg_pres(tetris_t *tetris, int ac, char **av);

int check_all_pieces(tetris_t *tetris);


int check_argv(int ac, char **av, tetris_t *tetris);
int set_default_debug(tetris_t *tetris);
int debug_mode(int ac, char **av, tetris_t *tetris);
int fill_debug(tetris_t *tetris);
int launch_game(tetris_t *tetris);
int check_next_av(char **av, int i);
int flag_left(tetris_t *tetris, char **av, int i);
int flag_right(tetris_t *tetris, char **av, int i);
int flag_turn(tetris_t *tetris, char **av, int i);
int flag_drop(tetris_t *tetris, char **av, int i);
int flag_quit(tetris_t *tetris, char **av, int i);
int flag_pause(tetris_t *tetris, char **av, int i);
int flag_next(tetris_t *tetris, char **av, int i);
int flag_level(tetris_t *tetris, char **av, int i);
int flag_map_size(tetris_t *tetris, char **av, int i);
int my_strcmp_custom(char *str1, char *str2);
int my_strlen_custom(char *str);
int print_tetriminos(char *folder, char *path, tetris_t *tetris);
int info_tetriminos(char **file_array, tetris_t *tetris);
int get_file_name(tetris_t *tetris, char *path);
char **change_order(char **folder, int size);
char **path_to_array(char *path, int len);
int my_str_isnum(char const *str);
char *my_strcpy_custom(char *new, char *src, int inc);
int save_place_l(tetris_t *tetris, char **av, int i);
int save_place_r(tetris_t *tetris, char **av, int i);
int save_place_t(tetris_t *tetris, char **av, int i);
int save_place_d(tetris_t *tetris, char **av, int i);
int save_place_q(tetris_t *tetris, char **av, int i);
int save_place_p(tetris_t *tetris, char **av, int i);
int save_place_w(tetris_t *tetris, char **av, int i);
int save_place_level(tetris_t *tetris, char **av, int i);

#endif /* MY_H_ */