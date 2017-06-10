/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:35:25 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/09 16:35:27 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		no_type(t_param *a)
{
	int res;
	int spaces;
	int new_start;

	res = 0;
	spaces = a->width - 1;
	new_start = ft_strchr0(a->extra, 0, '%');
	if (new_start > 0)
		ft_memmove(&a->extra[0], &a->extra[new_start],
				ft_strlen(a->extra) - new_start + 1);
	if (a->flag.n_flg == 0)
		put_chr_n(' ', spaces);
	ft_putchar(a->extra[0]);
	if (a->flag.n_flg)
		put_chr_n(' ', spaces);
	if (a->extra[1])
		ft_putstr(&(a->extra[1]));
	if (spaces > 0)
		res = spaces;
	return (res);
}
