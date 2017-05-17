/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:38:57 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/16 19:39:16 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include "libft.h"

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
	new->length = 0;
	new->type = 0;
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

void		parse(char *str)
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
		a->parameter = ft_atoi(str);
		delta = ft_getsize(a->parameter, 10) + 1;
	}
	if (str[delta + 1] == '#' || str[delta + 1] == '0' ||
			str[delta + 1] == '+' || str[delta + 1] == '-')
	{
		a->flag = ft_strsub(str, delta + 1, 1);
		delta++;
	}
	a->width = ft_atoi(&str[delta + 1]);
	if (a->width)
		delta = delta + ft_getsize(a->width, 10);
	if (ft_strchr(str, '.') > 0)
	{
		a->precision = ft_atoi(&str[delta + 1]);
		delta = delta + ft_getsize(a->precision, 10);
	}




}
	
void	ft_printf(char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;
	int i = 0;
	char *work_str;

	va_start(ap, fmt);
	printf("aaaaa=%i\n", atoi(".7"));
	work_str = get_work_str(fmt);
  	parse(work_str);

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
	long b = 5;

	ft_printf("!%1$10li,___%2$i,!!!%1$li", b, 14);
	printf("%00i\n", 5);
//	ft_printf("!%10li\n", b);

//	printf("%0o\n",b );
//	printf("res= %1$010.2f\n", 12.50);
//
//	printf("%3$lli  %2$#x\n; %1$d %1$#x", 16, 17, 15);
	t_param * tt;
 	tt = create_node();	

	return (0);
}

