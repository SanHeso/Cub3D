NAME = libcub.a

SRCS = 	\

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
				@echo $(CYAN) "$(NAME) COMPLETE!!" $(EOC)

%.o:		%.c
				${CC} ${CFLAGS} -c $< -o $@
				@echo $(GREEN) "TRANSFORMATION COMPLETE!!" $(EOC)

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