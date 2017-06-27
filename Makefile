# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 11:20:45 by mfranc            #+#    #+#              #
#    Updated: 2017/06/27 16:59:59 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror
CC = clang $(FLAGS)
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = $(addprefix $(SRCS_PATH)/, main.c)
OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libftprintf.a
INCLUDE = includes
LIBFT_INCLUDE = $(LIBFT_PATH)/includes
ALL_INCLUDE = -I $(INCLUDE) -I $(LIBFT_INCLUDE)

.PHONY: all clean flcean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $^ -o $@ $(ALL_INCLUDE) -L $(LIBFT_PATH) -lftprintf

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) -o $@ -c $< $(ALL_INCLUDE)

clean:
	@make clean -C $(LIBFT_PATH)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all
