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
		tokenizer2 \
		command_utils \
		pipes \
		built_ins_and_env/builtins_utils \
		built_ins_and_env/cd \
		built_ins_and_env/echo \
		built_ins_and_env/env_utils \
		built_ins_and_env/env \
		built_ins_and_env/exit \
		built_ins_and_env/export \
		built_ins_and_env/pwd \
		built_ins_and_env/unset \
		exec/exec \
		exec/exec_helpers \
		exec/exec_utils \
		exec/redir_utils \
		lexer/commands \
		lexer/cmd_helpers1 \
		lexer/cmd_helpers2 \
		lexer/redir_helpers \
		lexer/redirections

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
