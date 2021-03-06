/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:23:07 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/08 18:38:27 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

char g_lengths[8][3] = {"hh", "h", "l", "ll", "j", "z", "L", "t"};
char g_types[14][2] = {"s", "S", "p", "d", "D", "i", "o", "O", "u", "U",
	"x", "X", "c", "C"}	;

int		ft_strchr0(const char *str, int pos, int c)
{
	size_t	i;
	char	int_to_char;

	i = pos;
	int_to_char = c;
	while (i <= ft_strlen(str))
	{
		if (str[i] == int_to_char)
			return (i);
		i++;
	}
	return (-1);
}

t_param	*create_node(void)
{
	t_param *new;

	new = (t_param *)malloc(sizeof(t_param));
	new->parameter = 0;
	new->flag.is = 0;
	new->flag.p_flg = 0;
	new->flag.n_flg = 0;
	new->flag.h_flg = 0;
	new->flag.z_flg = 0;
	new->width = -1;
	new->precision = -1;
	new->length = -1;
	new->type = -1;
	new->extra = 0;
	new->spaces = 0;
	return (new);
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	char	*work_str;
	t_param	*a;
	int		start;
	int		res;

	va_start(ap, fmt);
	start = ft_strchr0(fmt, 0, '%');
	if (start == -1)
		return ((ft_putfree(ft_strdup(fmt))));
	ft_putfree(ft_strsub(fmt, 0, start));
	res = start;
	while (fmt[start])
	{
		work_str = get_work_str(&fmt[start]);
		a = parse(work_str);
		res += work_var(a, ap);
		start = start + ft_strlen(work_str);
		free(work_str);
		free(a->extra);
		free(a);
	}
	return (res);
}
