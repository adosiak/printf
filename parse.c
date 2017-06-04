/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:06:32 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/26 19:01:43 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int			str_in_str(char *str, int what)
{
	int i;

	i = 0;

	if (what == 1) // search length
		while (i < 8)
		{
			if(!ft_strcmp(str, g_lengths[i]))
				return(i);
			i++;
		}
	else if (what == 2) // search type
		while (i < 14)
		{
			if(!ft_strcmp(str, g_types[i]))
				return(i);
			i++;
		}
	return (-1);
}

void		get_length_type(char *str, int delta, t_param *a, int width_len)
{
	char *length;
	char *type;
	//width_len == 1: search for flag with one chr(h, l, j, z, l, t)
	//width_len == 2: search for flag with two chr(hh, ll);

	if (width_len > 2)
		return ;// ERROR_FUNC SHOULD BE HERE
	length = ft_strsub(str, delta + 1, width_len);
	a->length = str_in_str(length, 1);
	if (a->length >= 0)
	{
		delta = delta + width_len;
		type = ft_strsub(str, delta + 1, 1);
		a->type = str_in_str(type, 2);
		if(a->type >= 0)
			return ;
		else
		{
			delta = delta - width_len;
			get_length_type(str, delta, a, width_len + 1);
		}
	}
	else
	{
		type = ft_strsub(str, delta + 1, 1);
		a->type = str_in_str(type, 2);
		if(a->type >= 0)
			return ;
		else
			return ;// ERROR_FUNC SHOULD BE HERE
	}
}

int			get_delta(t_param *a, int *flag, char *str, int pres_flag)
{
	int delta;
	int i;

	delta = pres_flag;

	if (a->flag.n_flg)
		delta++;
	if (a->flag.p_flg)
			delta++;
	if (a->flag.z_flg)
			delta++;
	if (a->flag.h_flg)
			delta++;
	if (delta > 0)
		a->flag.is = 1;

	if (a->parameter)
		delta += ft_getsize(a->parameter, 10) + 1;

	if (a->width >= 0)
		delta = delta + ft_getsize(a->width, 10);
	if (a->precision >= 0)
		delta = delta + ft_getsize(a->precision, 10) + 1;
	if (a->length >= 0)
		delta +=ft_strlen(g_lengths[a->length]);
	if (a->type >= 0)
		delta++;
	i = delta + a->spaces + 1;
	while (a->type == -1 && str[i])
	{
		if (str[i] == ' ')
		{
			a->spaces++;
			*flag = 1;
		}
		else
			break ;
		i++;
	}
	return (delta + a->spaces);
}

void parse_flag(t_param *a, int *flag, char *str, int pres_flag)
{
	int pos;

	pos = get_delta(a, flag, str, pres_flag)+ 1;
	while (str[pos] == '#' || str[pos] == '+'|| str[pos] == '-' || str[pos] == '0' || str[pos] == ' ')
	{
	if (str[pos] == '#')
		a->flag.h_flg = 1;
	else if (str[pos] == '+')
		a->flag.p_flg = 1;
	else if (str[pos] == '-')
			a->flag.n_flg = 1;
	else if (str[pos] == '0')
		a->flag.z_flg = 1;
	pos = get_delta(a, flag, str, pres_flag)+ 1;
	}
}

t_param		*parse(char *str)
{
	t_param *a;
	int flag;
	int pos;
	int pres_flag;

	a = create_node();
	flag = 0;
	pres_flag = 0;

	if (ft_strchr0(str, 0, '$') > 0)
		a->parameter = ft_atoi(&str[1]);
//	printf("\nstr:%s\n",str);
	parse_flag(a, &flag, str, pres_flag);
	//printf("\n1.Print get_delta:%i\n",get_delta(a, &flag, str, pres_flag));


//	printf("2.Print get_delta:%i\n",get_delta(a, &flag, str, pres_flag));
	pos = get_delta(a, &flag, str, pres_flag) + 1;
	//printf("\nstr=%s\nw_pos=%i\n", str, w_pos);
	a->width = ft_atoi(&str[pos]);
	//printf("!!!!!!!Here: %s", &str[get_delta(a, &flag, str, pres_flag) + 1]);
	if (a->width == 0 && str[pos] != '0')
	{
		a->width = -1;
		//a->spaces = 0;
		//flag = 0;
	}
	/*printf("3.Print get_delta:%i\n",get_delta(a, &flag, str, pres_flag));
	printf("\nAAA:%s", &str[get_delta(a, &flag, str, pres_flag) + 1]);*/

	if (ft_strchr0(str, 0, '.') > 0)
	{
		pos = get_delta(a, &flag, str, pres_flag) + 1 + 1;// + 1 for '.'
		a->precision = ft_atoi(&str[pos]);

		if (!ft_isdigit(str[pos]))
	//		a->precision = ft_atoi(&str[pos]);
//		else
		//{
	 		pres_flag = -1;// in case "%.s"
		//	a->precision = 0;
		//}
	}
	pos = get_delta(a, &flag, str, pres_flag);
	if (ft_strchr0(str, 0, '.') > pos)
			a->precision = -1;
	get_length_type(str, pos, a, 1);
	//if (!ft+strstr[get_delta(a, &flag, str, pres_flag)])
	//DO I need this check?
/*	if (a->type >= 0)
		delta++;*/

	a->extra = ft_strdup(&str[get_delta(a, &flag, str, pres_flag) + 1]);
	return (a);
}

char		*get_work_str(char *str)
{
	int start;
	int end;
	char *res;
	int new_end;
	t_param *a;

	start = ft_strchr0(str, 0, '%');

	if (start < 0)
		return (0);
	end = ft_strchr0(str, start + 1, '%');
	if (end < 0)
		end = ft_strlen(str);

	res = ft_strsub(str, start, end);
	//printf("\nres in get_work_str=%s", res);
	a = parse(res);
	if (end != ft_strlen(str) && a->type == -1)
		res = ft_strjoin(ft_strsub(str, 0, end), get_work_str(&str[end]));
	return (res);
	//printf("\nstart=%i, end=%i\n", start, end);
	//handling %%
	/*if (end - start == 1)
	{
	//	printf("\nHERE\n");
		new_end = end;
		if (end != (int)ft_strlen(str))
			new_end = ft_strchr0(str,end + 1, '%');
	//	printf("\n new_end=%i\n", new_end);
		if (new_end < 0)
			new_end = ft_strlen(str);
		res = ft_strsub(str, start, new_end);
	}
	else
		res = ft_strsub(str, start, end);
	parse(res);
	return (res);*/
}
