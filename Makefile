# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 19:32:06 by hnewman           #+#    #+#              #
#    Updated: 2021/03/29 19:47:36 by hnewman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcub.a

SRCS = cub3d.c cub_utils.c cub_utils_2.c parser.c button_move.c calculate.c \
validation.c screenshot.c paint.c

OBJS = ${SRCS:.c=.o}

HEADER = cub3d.h

PATH_LIBFT = libft/

GREEN = "\033[0;32m"
CYAN = "\033[0;36m"
EOC = "\033[0m"

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
				@make -C ${PATH_LIBFT} bonus
				@ar rcs $(NAME) libft/*.o ${OBJS}
				$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(NAME)
				@echo $(CYAN) "$(NAME) COMPLETE!!" $(EOC)

%.o:		%.c
				$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
				@rm -f ${OBJS}
				@make -C ${PATH_LIBFT} clean
				@echo $(GREEN) "CLEAN COMPLETE!!" $(EOC)

fclean:		clean
				@rm -f $(NAME)
				@make -C ${PATH_LIBFT} fclean
				@echo $(GREEN) "FCLEAN COMPLETE!!" $(EOC)

re:			fclean all

.PHONY:		all clean fclean re
