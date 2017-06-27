/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 17:39:08 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "custom.h"

# define CONVS 	"sSpdDioOuUxXwcCbnNfF"
# define MODIFS "hlhhlljz"
# define FLAGS 	"#0123456789 -+*$.Lhlhhlljz"

typedef struct		s_datas
{
	char			*result;
	va_list			ap;
	char			*flags;
	int				*tmp_len;
	char			**cp_result;
	int				len;
	int				cplen;
	int				un_ord;
	int				pointer;
	int				fd;
}					t_datas;

typedef struct		s_flags
{
	int				dollar;
	int				precision;
	int				less;
	int				zero;
	int				diese;
	int				pointer;
	int				plus;
	int				space;
	int				padding;
}					t_flags;

int					ft_printf(const char *buff, ...);
int					ft_datas_init(t_datas *datas, char *buff);
int					ft_launch_process(t_datas *datas, char *buff);
char				*ft_get_unconvdatas(t_datas *datas, char *buff, size_t i);
int					ft_no_conv_manager(char *buff,
t_datas *datas, size_t conv_index);
void				ft_last_datasmanager(char conv, char **lastdatas);
char				*ft_exit(t_datas *datas);
int					ft_exit_current(t_datas *datas);
int					ft_exit_noconv(t_datas *datas, char *tmpsf);
char				*ft_exit_unconv(t_datas *datas, char *ucvchar);
char				*ft_exit_conv(t_datas *datas, char *argcvd);
char				*ft_fill_buff(t_datas *datas, char *buff);
int					ft_get_convdatas(t_datas *datas, char *buff);
char				*ft_get_lastdatas(t_datas *datas, char *buff, size_t i);
int					ft_flags_init(t_datas *datas, t_flags *flags);

int					ft_buff_customer(char **ucvchar);

int					ft_blue(char **s, char *buffpc, int *i);
int					ft_red(char **s, char *buffpc, int *i);
int					ft_green(char **s, char *buffpc, int *i);
int					ft_black(char **s, char *buffpc, int *i);
int					ft_yellow(char **s, char *buffpc, int *i);
int					ft_purple(char **s, char *buffpc, int *i);
int					ft_cyan(char **s, char *buffpc, int *i);
int					ft_grey(char **s, char *buffpc, int *i);
int					ft_eoc(char **s, char *buffpc, int *i);
int					ft_bold(char **s, char *buffpc, int *i);
int					ft_dim(char **s, char *buffpc, int *i);
int					ft_eos(char **s, char *buffpc, int *i);
int					ft_underlined(char **s, char *buffpc, int *i);
int					ft_blink(char **s, char *buffpc, int *i);
int					ft_reverse(char **s, char *buffpc, int *i);
int					ft_reverse(char **s, char *buffpc, int *i);
int					ft_italic(char **s, char *buffpc, int *i);
int					ft_hidden(char **s, char *buffpc, int *i);
int					ft_exit_clrnofind(char *color);
int					ft_exit_color_error(char *color);
int					ft_exit_multicolor(char *color, char *multicolor);

typedef int			(*t_customs)(char **s, char *buffpc, int *i);

char				*ft_get_s_conv(t_datas *datas);
char				*ft_get_ls_conv(t_datas *datas);
char				*ft_get_p_conv(t_datas *datas);
char				*ft_get_d_conv(t_datas *datas);
char				*ft_get_ld_conv(t_datas *datas);
char				*ft_get_i_conv(t_datas *datas);
char				*ft_get_o_conv(t_datas *datas);
char				*ft_get_lo_conv(t_datas *datas);
char				*ft_get_u_conv(t_datas *datas);
char				*ft_get_lu_conv(t_datas *datas);
char				*ft_get_x_conv(t_datas *datas);
char				*ft_get_lx_conv(t_datas *datas);
char				*ft_get_w_conv(t_datas *datas);
char				*ft_get_c_conv(t_datas *datas);
char				*ft_get_lc_conv(t_datas *datas);
char				*ft_get_b_conv(t_datas *datas);
char				*ft_get_n_conv(t_datas *datas);
char				*ft_get_ln_conv(t_datas *datas);
char				*ft_get_f_conv(t_datas *datas);
char				*ft_get_percent_conv(t_datas *datas);

typedef	char		*(*t_get_convs)(t_datas *datas);

int					ft_space(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i);
int					ft_plus(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i);
int					ft_diese(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i);
int					ft_zero(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i);
int					ft_less(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i);
int					ft_precision(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i);
int					ft_arg_precision(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i);
int					ft_n_arg_precision(t_datas *datas, int n,
		t_flags *flags, size_t *i);
int					ft_padding(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i);
int					ft_arg_padding(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i);
int					ft_n_arg_padding(t_datas *datas, int n,
		t_flags *flags, size_t *i);

typedef	int			(*t_get_flags)(t_datas *datas,
		char *strflag, t_flags *flags, size_t *i);

int					ft_d_space(char **argcvd, t_flags *flags);
int					ft_d_plus(char **argcvd, t_flags *flags);
int					ft_d_zero(char **argcvd, t_flags *flags);
int					ft_d_precision(char **argcvd, t_flags *flags);
int					ft_d_padding(char **argcvd, t_flags *flags);
int					ft_n_d(t_datas *datas, t_flags *flags);

int					ft_f_zero(char **argcvd, t_flags *flags);

int					ft_o_diese(char **argcvd, t_flags *flags);
int					ft_o_zero(char **argcvd, t_flags *flags);

unsigned int		ft_n_u(t_datas *datas, t_flags *flags);
unsigned long int	ft_n_lu(t_datas *datas, t_flags *flags);

int					ft_x_precision(char **argcvd, t_flags *flags);
int					ft_x_zero(char **argcvd, t_flags *flags);
int					ft_x_diese(char **argcvd, t_flags *flags);
int					ft_lx_diese(char **argcvd, t_flags *flags);

void				ft_aff_nulchar(t_datas *datas);
int					ft_zero_right_padding(char **argcvd,
		t_flags *flags, t_datas *datas);
int					ft_zero_left_padding(char **argcvd,
		t_flags *flags, t_datas *datas);
int					ft_c_padding(char **argcvd, t_flags *flags);
void				ft_aff_nulchar_clean(t_datas *datas);
char				*ft_launch_c_flags(char **argcvd, t_flags *flags);
int					ft_c_zero(char **argcvd, t_flags *flags);

char				*ft_n_s(t_datas *datas, t_flags *flags);
int					ft_s_precision(char **argcvd, t_flags *flags);
int					ft_ls_precision(char **argcvd, t_flags *flags);
typedef int			(*t_flags_func)(char **argcvd, t_flags *flags);

#endif
