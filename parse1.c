/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:06:32 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/09 15:46:28 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int			get_delta(t_param *a, int *flag, char *str, int pres_flag)
{
	int delta;
	int i;

	delta = pres_flag;
	(a->flag.n_flg) ? delta += a->flag.n_flg : 0;
	(a->flag.p_flg) ? delta += a->flag.p_flg : 0;
	(a->flag.z_flg) ? delta += a->flag.z_flg : 0;
	(a->flag.h_flg) ? delta += a->flag.h_flg : 0;
	(delta > 0) ? a->flag.is = 1 : 0;
	(a->parameter) ? delta += ft_getsize(a->parameter, 10) + 1 : 0;
	(a->width >= 0) ? delta = delta + ft_getsize(a->width, 10) : 0;
	(a->width == -2) ? delta++ : 0;
	(a->precision >= 0) ? delta = delta + ft_getsize(a->precision, 10) + 1 : 0;
	(a->precision == -2) ? delta += 2 : 0;
	(a->length >= 0) ? delta += ft_strlen(g_lengths[a->length]) : 0;
	(a->type >= 0) ? delta++ : 0;
	i = delta + a->spaces + 1;
	while (a->type == -1 && str[i] == ' ')
	{
		a->spaces++;
		i++;
	}
	(a->spaces) ? (*flag) = 1 : 0;
	return (delta < 0) ? 0 : delta + a->spaces;
}

void		get_length_type(char *str, int delta, t_param *a, int width_len)
{
	char *length;
	char *type;

	if (width_len > 2)
		return ;
	length = ft_strsub(str, delta + 1, width_len);
	a->length = str_in_str(length, 1);
	free(length);
	if (a->length >= 0)
	{
		delta = delta + width_len;
		type = ft_strsub(str, delta + 1, 1);
		a->type = str_in_str(type, 2);
		free(type);
		if (a->type >= 0)
			return ;
		else
			get_length_type(str, delta - width_len, a, width_len + 1);
	}
	else
	{
		type = ft_strsub(str, delta + 1, 1);
		a->type = str_in_str(type, 2);
		free(type);
	}
}

void		parse_flag(t_param *a, int *flag, char *str, int pres_flag)
{
	int pos;

	pos = get_delta(a, flag, str, pres_flag) + 1;
	while (str[pos] == '#' || str[pos] == '+' || str[pos] == '-'
			|| str[pos] == '0' || str[pos] == ' ')
	{
		if (str[pos] == '#')
			a->flag.h_flg++;
		else if (str[pos] == '+')
			a->flag.p_flg++;
		else if (str[pos] == '-')
			a->flag.n_flg++;
		else if (str[pos] == '0')
			a->flag.z_flg++;
		pos = get_delta(a, flag, str, pres_flag) + 1;
	}
}

void		parse_width_prec(t_param *a, int *flag, char *str, int *pres_flag)
{
	int		pos;

	pos = get_delta(a, flag, str, *pres_flag) + 1;
	a->width = ft_atoi(&str[pos]);
	if (a->width == 0 && str[pos] != '0')
	{
		if (str[pos] == '*')
			a->width = -2;
		else
			a->width = -1;
	}
	pos = get_delta(a, flag, str, *pres_flag) + 1;
	if (ft_strchr0(str, 0, '.') == pos)
	{
		pos++;
		a->precision = ft_atoi(&str[pos]);
		if (!ft_isdigit(str[pos]) && str[pos] != '*')
			*pres_flag = -1;
		if (str[pos] == '*')
			a->precision = -2;
	}
}

t_param		*parse(char *str)
{
	t_param	*a;
	int		flag;
	int		pos;
	int		pres_flag;

	a = create_node();
	flag = 0;
	pres_flag = 0;
	if (ft_strchr0(str, 0, '$') > 0)
		a->parameter = ft_atoi(&str[1]);
	parse_flag(a, &flag, str, pres_flag);
	parse_width_prec(a, &flag, str, &pres_flag);
	pos = get_delta(a, &flag, str, pres_flag);
	get_length_type(str, pos, a, 1);
	a->extra = ft_strdup(&str[get_delta(a, &flag, str, pres_flag) + 1]);
	return (a);
}
