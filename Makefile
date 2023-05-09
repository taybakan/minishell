NAME	= minishell

SRC		= main.c input.c ./builtin/env.c ./builtin/pwd.c ./builtin/exit.c ./builtin/echo.c ./builtin/export.c ./builtin/unset.c

LIB		= ./lib/libft/libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

RLFLAGS	= -lreadline

OBJS	= $(SRC:.c=.o)

RM		= rm -rf

all		:	$(LIB) $(NAME) $(OBJS)

$(LIB)	:
	@make -C ./lib/libft
	@echo "\033[0;36m" ---LIBFT COMPILED--- "\033[0;37m"

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(RLFLAGS) $(SRC) -o $(NAME) $(LIB)

clean	:
	$(RM) $(OBJS)
	@make clean -C ./lib/libft

fclean	:	clean
	$(RM) $(NAME)
	@make fclean -C ./lib/libft

re		:	fclean all

.PHONY	:	all clean fclean re