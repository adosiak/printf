/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:26:00 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/07 18:27:55 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HEADER_H
#ifdef HEADER_H

# include <stdarg.h>
# include <stdio.h>//delete thisx

typedef struct	s_flg
{
	int			is;
	int			p_flg;
	int			n_flg;
	int			h_flg;
	int			z_flg;
}				t_flg;

typedef struct	s_param
{
	int			parameter;
	t_flg		flag;
	int			width;
	int			precision;
	int			length;
	int			type;
	char		*extra;
	int			spaces;
}				t_param;

extern char		g_lengths[8][3];
extern char		g_types[14][2];

int				str_int_str(char *str, int what);
char			*get_work_str(char *str);
int				get_delta(t_param *a, int *flag, char *str, int pres_flag);
t_param			*parse(char *str);
void			get_length_type(char *str, int delta, t_param *a, int width_len);
int				ft_strchr0(const char *str, int pos, int c);
t_param			*create_node(void);
int				work_var(t_param *a, va_list ap);
int				type_s(t_param *a, va_list ap);
int				type_di(t_param *a, va_list ap);
int				type_c(t_param *a, va_list ap);
int				type_uox(t_param *a, va_list ap);
int				no_type(t_param *a);

int				type_p(t_param *a, va_list ap);
int				ft_strchr0(const char *str, int pos, int c);
int				put_chr_n(char c, int n);
t_param			*create_node(void);
int				ft_printf(char *fmt, ...);
char			*unsign_itoa_base(unsigned long long int value, int base);
unsigned long long get_uox(t_param *a, va_list ap);
long long		get_di(t_param *a, va_list ap);
int				ft_putfree(char *str);
void			handle_star(t_param *a, va_list ap);

#endif
