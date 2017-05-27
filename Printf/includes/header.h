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

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>//delete this


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

size_t				ft_strlen(char const *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncat(char *str, const char *add, size_t n);

char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				ft_strclr(char *s);
void				ft_strrev(char *str);
int					ft_strcmp(const char *dest, const char *src);
int					ft_atoi(const char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);//?
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_itoa_base(int value, int base);
int					ft_getsize(int value, int base);


int				str_int_str(char *str, int what);
char			*get_work_str(char *str);
int				get_delta(t_param *a);
t_param			*parse(char *str);
void			get_length_type(char *str, int delta, t_param *a, int width_len);
int				ft_strchr0(const char *str, int pos, int c);
t_param			*create_node(void);
int work_var(t_param *a, va_list ap);
int type_s(t_param *a, va_list ap);
void type_d(t_param *a, va_list ap);
void type_p(t_param *a, va_list ap);


#endif
