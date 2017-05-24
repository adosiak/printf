/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:38:57 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/23 18:08:32 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include "libft.h"

char g_lengths[8][3] = {"hh","h","ll","l","j","z","L","t"};
char g_types[14][2] = {"s","S","p","d","D","i","o","O","u","U","x","X","c","C"}	;

int		ft_strchr0(const char *str, int c)
{
	size_t	i;
	char	int_to_char;

	i = 0;
	int_to_char = c;
	while (i <= ft_strlen(str))
	{
		if (str[i] == int_to_char)
			return (i);
		i++;
	}
	return (-1);
}

t_param		*create_node(void)
{
	t_param *new;

	new = (t_param *)malloc(sizeof(t_param));
	new->parameter = 0;
	new->flag = 0;
	new->width = 0;
	new->precision = -1;
	new->length = -1;
	new->type = -1;
	new->extra = 0;
	return (new);
}

char		*get_work_str(char *str)
{
	int start;
	int end;
	char *res;

	start = ft_strchr0(str, '%');
	if (start < 0)
		return (0);
	else
		end = ft_strchr0(&str[start + 1], '%');
	if (end < 0)
		end = ft_strlen(str) - 1;
	res = ft_strsub(str, start, end + 1);
	printf("RES=%s\n",res);
	return (res);
}

int			str_in_str(char *str, int what)
{
	int i;

	i = 0;
	if (what == 1) // search length
	{
		while (i < 8)
		{
			if(!ft_strcmp(str, g_lengths[i]))
				return(i);
			i++;
		}
	}
	else if (what == 2) // search type
	{
		while (i < 14)
		{
			if(!ft_strcmp(str, g_types[i]))
				return(i);
			i++;
		}
	}
	return (-1);
}

void		get_length_type(char *str, int *delta, t_param *a, int width_len)
{
	char *length;
	char *type;
	//width_len == 1: search for flag with one chr(h, l, j, z, l, t)
	//width_len == 2: search for flag with two chr(hh, ll);

	if (width_len > 2)
		return ;// ERROR_FUNC SHOULD BE HERE
	length = ft_strsub(str, *delta + 1, width_len);
	a->length = str_in_str(length, 1);
	if (a->length >= 0)
	{
		*delta = *delta + width_len;
		type = ft_strsub(str, *delta + 1, 1);
		a->type = str_in_str(type, 2);
		if(a->type >= 0)
			return ;
		else
		{
			*delta = *delta - width_len;
			get_length_type(str, delta, a, width_len + 1);
		}
	}
	else
	{
		type = ft_strsub(str, *delta + 1, 1);
		a->type = str_in_str(type, 2);
		if(a->type >= 0)
			return ;
		else
			return ;// ERROR_FUNC SHOULD BE HERE
	}
}

t_param		*parse(char *str)
{
	int i;
	int start;
	int end;
	t_param *a;
	int delta;

	i = 0;
	delta = 0;
	a = create_node();
	if (ft_strchr0(str, '$') > 0)
	{
		a->parameter = ft_atoi(&str[1]);
		delta = ft_getsize(a->parameter, 10) + 1;
	}
	if (str[delta + 1] == '#' || str[delta + 1] == '0' ||
			str[delta + 1] == '+' || str[delta + 1] == '-')
	{
		a->flag = ft_strsub(str, delta + 1, 1);
		delta++;
	}
	a->width = ft_atoi(&str[delta + 1]);
//	printf("delta BEFORE=%i\n(ft_getsize=%i)\n", delta, ft_getsize(a->width, 10));
	if (a->width)
		delta = delta + ft_getsize(a->width, 10);
//	printf("delta AFTER=%i\n", delta);
	if (ft_strchr(str, '.') > 0)
	{
		delta++; //added for '.'
		a->precision = ft_atoi(&str[delta + 1]);
		delta = delta + ft_getsize(a->precision, 10);
	}
	get_length_type(str, &delta, a, 1);

	//DO I need this check?
	if (a->type >= 0)
		delta++;
	a->extra = ft_strdup(&str[delta + 1]);
	return (a);
}
	
void	ft_printf(char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;
	int i = 0;
	char *work_str;
	t_param *a;

	va_start(ap, fmt);
	printf("aaaaa=%i\n", atoi(".7"));
	work_str = get_work_str(fmt);
  	a = parse(work_str);
	printf("\nparameter=%i\nflag=%s\nwidth=%i\nprecision=%i\nlength=%s\ntype=%s\nextra=%s\n", a->parameter, a->flag, a->width, a->precision, g_lengths[a->length], g_types[a->type], a->extra);

//	va_copy(ap2, ap);
	while (fmt[i])
	{
		if(fmt[i] == 'd')
		{
			d = va_arg(ap, int);
			printf("%d\n", d);
		}
		i++;
	}
}

int		main(void)
{
	char a[20] = "HEllo";
int	b = 5;

	ft_printf("!%1$#1.56i,___%2$i,!!!%1$li", b, 14);
//	printf("%00i\n", 5);
//	ft_printf("!%10li\n", b);

//	printf("%0o\n",b );
//	printf("res= %1$010.2f\n", 12.50);
//
//	printf("%3$li  %2$#x\n; %1$d %1$#x", 16, 17, b);
	t_param * tt;
 	tt = create_node();	
	return (0);
}

