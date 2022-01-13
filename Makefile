# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:43:07 by trlevequ          #+#    #+#              #
#    Updated: 2019/02/07 10:24:31 by jnoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH	=	includes/

INC			=	includes/lem_in.h

SRC_PATH	=	srcs/
SRC_PATH2	=	visual/

SRC_NAME 	=	lem_in.c \
				ft_exit.c \
				ft_check_line.c \
                ft_check.c \
                ft_list.c \
                ft_print_ants.c \
                ft_fill.c \
				ft_fill_path.c \
				ft_stack.c \
                ft_roads.c \
				ft_start_end.c \
				ft_fill_roads.c \
				ft_path.c \
				ft_ants.c \
				ft_reset_values.c \
                ft_free.c 

SRC_NAME2 	=	visual.c	\
				ft_check_visual.c \
				ft_create_tab_rooms.c \
				ft_create_tab_tubes.c \
				ft_fill_tab_ants.c \
				ft_create_tab_ants.c \
				ft_exit.c \
				ft_check_line.c \
                ft_check.c \
                ft_list.c \
                ft_print_ants.c \
                ft_fill.c \
				ft_fill_path.c \
				ft_stack.c \
                ft_roads.c \
				ft_fill_roads.c \
				ft_path.c \
				ft_ants.c \
				ft_reset_values.c \
				graph.c	\
				put_tubes_in_tab.c \
				get_bold_tube.c \
				draw_ant.c \
				draw_ant1.c \
				draw_ant2.c \
				draw_ant3.c \
				draw_ant4.c \
				size_path.c \
				circle_shapes.c \
				init.c \
                ft_free.c 


OBJ_PATH	=	obj/
OBJ_PATH2	=	obj2/

CPPFLAGS	=	-Iincludes

LDFLAGS		=	-Llibft
LDLIBS		=	-lft

NAME		=	lem-in
NAME2		=	visu-hex

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_NAME2	=	$(SRC_NAME2:.c=.o)

SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
SRC2		=	$(addprefix $(SRC_PATH2),$(SRC_NAME2))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ2		=	$(addprefix $(OBJ_PATH2),$(OBJ_NAME2))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@
	@echo "$(NAME) created"

$(NAME2): $(OBJ2)
	@make -C libft/
	@$(CC) $(CFLAGS) -Iincludes $(LDFLAGS) $(LDLIBS) $(OBJ2) -o $(NAME2) visual/minilibX_macos/libmlx.a -framework OpenGL -framework AppKit
	@echo "$(NAME2) created"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c $(INC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH2)%.o : $(SRC_PATH2)%.c $(INC)
	@mkdir $(OBJ_PATH2) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

lib_make_fclean:
	@make -C libft/ fclean

lib_make_clean:
	@make -C libft/ clean

clean:
	@rm -rf $(OBJ) $(OBJ2) $(OBJ_PATH) $(OBJ_PATH2)
	@echo "objs suppressed"

fclean: clean lib_make_fclean
	@rm -rf $(NAME) $(NAME2)
	@echo "exec suppressed"

re: lib_make_fclean fclean all

.PHONY:	all, clean, fclean, re
