/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:42:14 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/29 17:42:17 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

void type_d_help(t_param *a, int d, int *spaces, int *zeros)
{
	char *print_res;
	int neg;

	neg = 0;
	print_res = ft_itoa_base(d, 10);
	if(d == 0 && a->precision == 0)
		print_res = 0;
	if (a->width > 0 && a->width >= ft_strlen(print_res))
		*spaces = a->width - ft_strlen(print_res);
	if (a->precision != -1 && (a->precision >= ft_getsize(d, 10)))
		*zeros = a->precision - ft_getsize(d, 10);
	if ((a->flag && ft_strcmp(a->flag, "0") == 0) && a->precision == -1)
		*zeros = *spaces;
	if (d < 0)
			neg = 1;
	if (!a->flag || ft_strcmp(a->flag, "-") != 0)
	{
		if (a->flag && ft_strcmp(a->flag, "+") == 0 && !neg)
			(*spaces)--;
		put_chr_n(' ', *spaces - *zeros);
	}
	if (neg)
			ft_putstr("-");
	else if (a->flag && ft_strcmp(a->flag, "+") == 0)
		ft_putstr("+");
	put_chr_n('0', *zeros);
	ft_putstr(&print_res[neg]);
}

int type_d(t_param *a, va_list ap)
{
	int res;
	int d;
	int spaces;
	int zeros;

	spaces = 0;
	zeros = 0;
	res = 0;
	d = va_arg(ap, int);
	type_d_help(a, d, &spaces, &zeros);

	if (a->flag && ft_strcmp(a->flag, "-") == 0)
		put_chr_n(' ', spaces - zeros);
	if ((a->flag && ft_strcmp(a->flag, "+") == 0) || d < 0)
		res++;

	res += ft_getsize(d, 10) + ft_max(spaces, zeros);
	if(d == 0 && a->precision == 0)
		res--;
	//printf("\nres=%i",res);
	return (res);
}
