# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 20:18:37 by mgalecki          #+#    #+#              #
#    Updated: 2024/03/30 20:18:39 by mgalecki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_printf_char.c ft_printf_str.c ft_printf_ptr.c \
	ft_printf_nbr.c ft_printf_un_nbr.c ft_printf_hex_low.c \
	ft_printf_hex_upp.c ft_printf.c

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = gcc
RM = rm -f
CFFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
