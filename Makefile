# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 19:32:06 by hnewman           #+#    #+#              #
#    Updated: 2021/04/24 08:49:01 by hnewman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = includes/cub3d.h

SRCS = cub3d.c cub_utils.c cub_utils_2.c parser.c button_move.c calculate.c \
validation.c screenshot.c paint.c validation_2.c texturing.c sprite.c \
validation_3.c

SRCS_DIR = $(addprefix src/, $(SRCS))

OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS_DIR))

OUT_DIR = obj

PATH_LIBFT = libft/libft.a

GREEN = "\033[0;32m"
CYAN = "\033[0;36m"
EOC = "\033[0m"

CC = @gcc

CFLAGS = -g -Wall -Werror -Wextra

INCLUDE = -IMLX -Iincludes

all:		$(OUT_DIR) $(PATH_LIBFT) $(PATH_MLX) $(NAME)

obj/%.o:	src/%.c
				@$(CC) $(CFLAGS) -IMLX -c $< -o $@

$(NAME):	$(OBJS) $(PATH_LIBFT) $(HEADER)
				$(CC) $(OBJS) MLX/libmlx.a $(PATH_LIBFT) $(INCLUDE) -framework OpenGL -framework AppKit -o $(NAME)
				@echo $(CYAN) "$(NAME) COMPLETE!!" $(EOC)

$(OUT_DIR):
				@mkdir -p $@
				@echo $(GREEN) "$@ DIRECTION CREATED!!" $(EOC)

$(PATH_LIBFT):
				@make -C libft/ bonus
				@echo $(CYAN) "libft.a COMPLETE!!" $(EOC)

$(PATH_MLX):
				@make -C MLX/ re
				@echo $(CYAN) "libmlx.a COMPLETE!!" $(EOC)

clean:
				@rm -rf $(OUT_DIR)
				@make -C libft/ clean
				@echo $(GREEN) "CLEAN COMPLETE!!" $(EOC)

fclean:		clean
				@rm -f $(NAME)
				@make -C libft/ fclean
				@echo $(GREEN) "FCLEAN COMPLETE!!" $(EOC)

re:			fclean all

.PHONY:		all clean fclean re
