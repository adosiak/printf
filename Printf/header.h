/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:26:00 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/24 15:15:11 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HEADER_H
# ifdef HEADER_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>//delete this


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
int				ft_strchr0(const char *str, int c);
t_param			*create_node(void);
void work_var(t_param *a, va_list ap);
void type_s(t_param *a, va_list ap);
void type_d(t_param *a, va_list ap);
void type_p(t_param *a, va_list ap);


#endif
