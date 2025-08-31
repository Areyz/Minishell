CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = minishell
RM = rm -f
SRC = 	main \
		main_sub \
		signals \
		cleanup \
		cleanup_free \
		tokenizer \
		commands/cd \
		commands/echo \
		commands/env_utils \
		commands/env \
		commands/exit \
		commands/export \
		commands/pwd \
		commands/unset \
#extortion/do_extortion \
		env/childpar \
		env/do_pipe \
		env/envhandle \
		env/findpath \
		commands/export \
		commands/export&env
#utils \ parsing

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
