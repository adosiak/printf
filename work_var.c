/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:26:24 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/28 17:09:23 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		work_var(t_param *a, va_list ap)
{
	int res;

	res = 0;

	if (a->type != -1)
	{
		if (a->spaces != 0)
		{
			ft_putstr(" ");
			res++;
		}
	if (a->type == 0)
		res += type_s(a, ap);
	if (a->type == 2)
		res += type_p(a, ap);
	if (a->type == 3 || a->type == 5)
		res += type_di(a, ap);
	if (a->type >= 6 && a->type <= 11)
		res += type_uox(a, ap);
	if (a->type == 12)
		res += type_c(a, ap);
	ft_putstr(a->extra);
}
if (a->type == -1)
	res += no_type(a);
//printf("\na->extra=%s, res here:%d\n",a->extra, res);
return (res + ft_strlen(a->extra));
}

void	put_chr_n(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
}
