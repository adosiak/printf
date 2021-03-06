/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:27:03 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/09 15:45:46 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		type_p(t_param *a, va_list ap)
{
	unsigned long long	p;
	int					res;
	int					spaces;
	char				*str;
	char				*tmp;

	res = 0;
	p = (unsigned long long)va_arg(ap, void *);
	tmp = unsign_itoa_base(p, 16);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	spaces = 0;
	if (a->width > res)
		spaces = a->width - res;
	if (a->flag.n_flg == 0)
		put_chr_n(' ', spaces);
	res = ft_putfree(str);
	if (a->flag.n_flg)
		put_chr_n(' ', spaces);
	res = res + spaces;
	return (res);
}
