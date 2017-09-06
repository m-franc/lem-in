# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 11:20:45 by mfranc            #+#    #+#              #
#    Updated: 2017/09/06 11:25:01 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CC = gcc $(FLAGS)
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = $(addprefix $(SRCS_PATH)/, main.c						\
	   							  parsing/ft_is_command.c		\
								  parsing/ft_parse_file.c		\
								  parsing/ft_store_command.c	\
								  parsing/ft_push_data.c		\
								  parsing/ft_check_room.c		\
								  ft_display.c					\
								  graph/ft_build_graph.c		\
								  graph/ft_sort_graph.c			\
								  graph/ft_graph_sitting.c		\
								  graph/ft_build_adj_list.c		\
								  graph/ft_build_tunnels.c		\
								  ways/ft_cross_map.c			\
								  ways/ft_init_ants.c			\
								  ways/ft_init_ways.c			\
								  ways/ft_delete_ants.c			\
								  ft_exit.c						\
								  graph/ft_del_datas_graph.c	\
								  parsing/ft_del_data_store.c)
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
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)/parsing
	@mkdir -p $(OBJS_PATH)/graph
	@mkdir -p $(OBJS_PATH)/ways
	$(CC) -o $@ -c $< $(ALL_INCLUDE)

clean:
	@make clean -C $(LIBFT_PATH)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

git:
	git add -u; git commit -m "WIP"; git push
