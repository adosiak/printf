/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:30:47 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/09 16:31:11 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int			str_in_str(char *str, int what)
{
	int i;

	i = 0;
	if (what == 1)
		while (i < 8)
		{
			if (!ft_strcmp(str, g_lengths[i]))
				return (i);
			i++;
		}
	else if (what == 2)
		while (i < 14)
		{
			if (!ft_strcmp(str, g_types[i]))
				return (i);
			i++;
		}
	return (-1);
}

int			get_end(char *str, int start)
{
	int end;

	end = ft_strchr0(str, start + 1, '%');
	if (end < 0)
		end = ft_strlen(str);
	return (end);
}

char		*get_work_str(char *str)
{
	int		start;
	int		end;
	char	*res;
	t_param	*a;
	char	*tmp;

	start = ft_strchr0(str, 0, '%');
	if (start < 0)
		return (0);
	end = get_end(str, start);
	if (end - start == 1)
		return (ft_strsub(str, 0, get_end(str, end)));
	res = ft_strsub(str, start, end);
	a = parse(res);
	free(a->extra);
	free(a);
	if (end != (int)ft_strlen(str) && a->type == -1)
	{
		tmp = ft_strsub(str, 0, end);
		res = ft_strjoin(tmp, get_work_str(&str[end]));
		free(tmp);
	}
	return (res);
}
