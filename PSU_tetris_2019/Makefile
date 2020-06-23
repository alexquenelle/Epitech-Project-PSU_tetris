##
## EPITECH PROJECT, 2019
## new_navy
## File description:
## Makefile
##

SRC	=	src/help.c	\
		src/prepare_game.c	\
		src/calc_fct.c	\
		src/cpy_fct.c	\
		src/tetriminos_path.c	\
		src/start_game.c	\
		src/create_game_board.c	\
		src/tetri_rotate.c	\
		src/cpy_array_list.c	\
		src/check_error_tetri.c	\
		src/check_error_tetri_2.c	\
		src/tetrimino_setup.c	\
		src/choose_piece.c	\
		src/disp_color_1.c	\
		src/disp_color_2.c	\
		src/int_to_str.c	\
		src/get_info.c	\
		src/display_info.c	\
		src/ingame_time.c	\
		src/key_handling.c	\
		src/check_moving.c	\
		src/ingame_display.c	\
		src/end_game.c	\
		src/board_update.c	\
		src/check_collision.c	\
		src/change_order.c \
		src/path_to_array.c	\
		src/check_my_argv.c	\
		src/my_flag.c	\
		src/my_flag_bis.c	\
		src/my_strcpy_custom.c	\
		src/print_file.c	\
		src/update_new_keys.c	\
		src/launch_game.c	\
		src/error_handling_debug.c	\
		src/error_handling_debug_bis.c	\
		src/check_all_pieces.c	\
		src/check_collision_1.c	\
		src/check_moving_1.c	\
		src/display_next.c	\
		src/piece_to_board.c

LIB	=	lib/my_display.c	\
		lib/my_printf.c	\
		lib/my_strcmp.c	\
		lib/my_board_display.c	\
		lib/my_str_isnum.c

MAIN	=	src/main.c

CFLAGS	=	-g -I./include -lncurses

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	tetris

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

all: $(NAME)

tests_run:
	@rm -f *.gcda *.gcno
	gcc -o unit_tests $(SRC) $(LIB) tests/*.c $(CFLAGS) --coverage -lcriterion
	./unit_tests
	rm -f unit_tests
	rm -f test_*

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	rm -f $(OBJ)
	@rm -f *.gc*

fclean:	clean
	rm -f $(NAME)

re: fclean all