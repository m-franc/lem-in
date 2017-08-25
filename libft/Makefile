# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 18:43:40 by mfranc            #+#    #+#              #
#    Updated: 2017/08/23 20:50:56 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = gcc $(FLAGS)

INCLUDES = includes

SRCS = 	mems/ft_memset.c				\
		mems/ft_bzero.c 				\
		mems/ft_memcpy.c				\
		mems/ft_memccpy.c 			\
		mems/ft_memmove.c			\
		mems/ft_memchr.c				\
		mems/ft_memcmp.c				\
		strs/ft_strlen.c				\
		strs/ft_tablen.c				\
		strs/ft_strdup.c				\
		strs/ft_strcpy.c				\
		strs/ft_strncpy.c			\
		strs/ft_strcat.c				\
		strs/ft_strncat.c			\
		strs/ft_strlcat.c			\
		strs/ft_strchr.c				\
		strs/ft_strrchr.c			\
		strs/ft_strstr.c				\
		strs/ft_strnstr.c			\
		strs/ft_strncmp.c			\
		strs/ft_strcmp.c				\
		convs/ft_atoi.c				\
		convs/ft_atoui.c				\
		detects/ft_isalpha.c			\
		detects/ft_isdigit.c			\
		detects/ft_isalnum.c			\
		detects/ft_isprint.c			\
		detects/ft_isascii.c			\
		detects/ft_toupper.c			\
		detects/ft_tolower.c			\
		mems/ft_memalloc.c			\
		mems/ft_memdel.c				\
		strs/ft_strnew.c				\
		strs/ft_strdel.c				\
		strs/ft_strclr.c				\
		strs/ft_striter.c			\
		strs/ft_striteri.c			\
		strs/ft_strmap.c				\
		strs/ft_strmapi.c			\
		strs/ft_strequ.c				\
		strs/ft_strnequ.c			\
		strs/ft_strsub.c				\
		strs/ft_strjoin.c			\
		strs/ft_strtrim.c			\
		puts/ft_putstr.c				\
		puts/ft_puttab.c				\
		strs/ft_strsplit.c			\
		puts/ft_putendl.c			\
		puts/ft_putchar_fd.c			\
		puts/ft_putchar.c			\
		puts/ft_putstr_fd.c			\
		puts/ft_putendl_fd.c			\
		puts/ft_putint_fd.c			\
		puts/ft_putuint_fd.c			\
		lists/ft_lstnew.c				\
		lists/ft_lststrnew.c			\
		lists/ft_lstdelone.c			\
		lists/ft_lstdel.c				\
		lists/ft_lstadd.c				\
		lists/ft_lstiter.c			\
		lists/ft_lstmap.c				\
		strs/ft_countword.c			\
		detects/ft_isword.c				\
		mems/ft_tabnew.c				\
		maths/ft_sqrt.c				\
		strs/ft_strsplit_tolist.c	\
		puts/ft_putlist.c			\
		lists/ft_listcount.c			\
		strs/get_next_line.c			\
		convs/ft_itoa.c				\
		convs/ft_uitoa.c				\
		convs/ft_ilen.c				\
		convs/ft_uilen.c				\
		puts/ft_putint.c				\
		puts/ft_putuint.c			\
		puts/ft_putptr.c				\
		convs/ft_ftoa.c				\
		strs/ft_strspn.c				\
		strs/ft_strcspn.c			\
		puts/ft_putnstr.c			\
		ft_printf/ft_printf.c		\
		convs/ft_convbase.c			\
		maths/ft_power.c		\
		strs/ft_strlenuntil.c		\
		convs/ft_wctoa.c			\
		convs/ft_vtob.c			\
		strs/ft_strrev.c			\
		strs/ft_straddchar.c		\
		puts/ft_putbits.c		\
		convs/ft_wstrtoa.c			\
		strs/ft_wstrlen.c			\
		puts/ft_putwstr.c		\
		puts/ft_putwendl.c			\
		puts/ft_putwchar.c			\
		puts/ft_putwstr_fd.c		\
		puts/ft_putwendl_fd.c	\
		puts/ft_putwchar_fd.c		\
		convs/ft_vtop.c			\
		puts/ft_putintendl.c		\
		puts/ft_putintendl_fd.c			\
		puts/ft_putptr_fd.c			\
		puts/ft_putptrendl.c			\
		puts/ft_putptrendl_fd.c			\
		puts/ft_putuintendl_fd.c		\
		puts/ft_putuintendl.c			\
		ft_printf/convs/s/ft_s_conv.c	\
		ft_printf/convs/ls/ft_ls_conv.c	\
		ft_printf/convs/p/ft_p_conv.c	\
		ft_printf/convs/d/ft_d_conv.c	\
		ft_printf/convs/f/ft_f_conv.c	\
		ft_printf/convs/ld/ft_ld_conv.c	\
		ft_printf/convs/o/ft_o_conv.c	\
		ft_printf/convs/lo/ft_lo_conv.c	\
		ft_printf/convs/u/ft_u_conv.c	\
		ft_printf/convs/lu/ft_lu_conv.c	\
		ft_printf/convs/x/ft_x_conv.c	\
		ft_printf/convs/lx/ft_lx_conv.c	\
		ft_printf/convs/w/ft_w_conv.c	\
		ft_printf/convs/c/ft_c_conv.c	\
		ft_printf/convs/lc/ft_lc_conv.c	\
		ft_printf/convs/b/ft_b_conv.c	\
		ft_printf/convs/n/ft_n_conv.c	\
		ft_printf/convs/ln/ft_ln_conv.c	\
		ft_printf/ft_fill_buff.c		\
		ft_printf/convs/percent/ft_percent_conv.c	\
		ft_printf/convs/parse_flags/ft_parse_flags.c	\
		ft_printf/convs/parse_flags/ft_precision.c	\
		ft_printf/convs/parse_flags/ft_padding.c	\
		ft_printf/convs/parse_flags/ft_lzdps.c		\
		puts/ft_putstrcolor.c				\
		ft_printf/convs/ft_exit_conv.c		\
		ft_printf/ft_exit_last.c			\
		ft_printf/convs/d/ft_d_precision.c		\
		ft_printf/convs/x/ft_x_precision.c		\
		ft_printf/convs/x/ft_x_zero.c		\
		ft_printf/convs/d/ft_d_padding.c	\
		ft_printf/convs/c/ft_c_padding.c	\
		ft_printf/convs/d/ft_d_space.c		\
		ft_printf/convs/d/ft_d_plus.c	\
		ft_printf/convs/d/ft_d_zero.c	\
		ft_printf/convs/o/ft_o_diese.c	\
		ft_printf/convs/x/ft_x_diese.c	\
		ft_printf/convs/lx/ft_lx_diese.c	\
		ft_printf/convs/c/ft_nulchar.c	\
		ft_printf/convs/s/ft_s_precision.c	\
		ft_printf/convs/ls/ft_ls_precision.c	\
		ft_printf/ft_last_datasmanager.c	\
		ft_printf/customs/ft_buff_customer.c	\
		ft_printf/customs/ft_eoc.c	\
		ft_printf/customs/ft_red.c	\
		ft_printf/customs/ft_green.c	\
		ft_printf/customs/ft_black.c	\
		ft_printf/customs/ft_yellow.c	\
		ft_printf/customs/ft_purple.c	\
		ft_printf/customs/ft_cyan.c	\
		ft_printf/customs/ft_grey.c	\
		ft_printf/customs/ft_blue.c	\
		ft_printf/customs/ft_bold.c	\
		ft_printf/customs/ft_dim.c	\
		ft_printf/customs/ft_eos.c	\
		ft_printf/customs/ft_underlined.c	\
		ft_printf/customs/ft_blink.c	\
		ft_printf/customs/ft_reverse.c	\
		ft_printf/customs/ft_hidden.c	\
		ft_printf/customs/ft_italic.c	\
		strs/ft_tablen.c		\
		strs/ft_tabdel.c		\
		maths/ft_sort_int_tab.c	\
		maths/ft_get_median.c	\
		maths/ft_abs.c			\
		detects/ft_str_isdigit.c	\
		maths/ft_fibonacci.c

OBJECTS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) -c $< -o $@ -I $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
