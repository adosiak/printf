/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:26:00 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/26 18:49:29 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HEADER_H
# ifdef HEADER_H

# include <stdarg.h>
# include <stdio.h>//delete thisx


typedef struct	s_param
{
	int			parameter;
	char		*flag;
	int 		width;
	int			precision;
	int			length;
	int			type;
	char		*extra;
}				t_param;

extern char		 g_lengths[8][3];
extern char		 g_types[14][2];

int				str_int_str(char *str, int what);
char			*get_work_str(char *str);
int				get_delta(t_param *a);
t_param			*parse(char *str);
void			get_length_type(char *str, int delta, t_param *a, int width_len);
int				ft_strchr0(const char *str, int pos, int c);
t_param			*create_node(void);
int work_var(t_param *a, va_list ap);
int type_s(t_param *a, va_list ap);
int type_d(t_param *a, va_list ap);
int type_c(t_param *a, va_list ap);
int type_u(t_param *a, va_list ap);

void type_p(t_param *a, va_list ap);
int		ft_strchr0(const char *str, int pos, int c);
void	put_chr_n(char c, int n);
t_param		*create_node(void);// maybe I don't need this?
int		ft_printf(char *fmt, ...);

#endif
