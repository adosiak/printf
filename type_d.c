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

void type_di_help(t_param *a, long long d, int *spaces, int *zeros)
{
	char *print_res;
	int neg;

	neg = 0;
	print_res = ft_itoa_base(d, 10);
	if (d < 0)
			neg = 1;
	//printf("HEREEE:d=%lld\ns=%s\n", d, print_res);
	if(d == 0 && a->precision == 0)
		print_res = 0;
	//printf("HEREEE:d=%lld\ns=%s\n", d, &print_res[0]);

	if (a->flag.n_flg)
		a->flag.z_flg = 0;
	*spaces = a->width - ft_strlen(print_res);
	if (a->flag.p_flg && !neg)
			(*spaces)--;
	if (a->precision >= ft_getsize(d, 10))
		*zeros = a->precision - ft_getsize(d, 10);
	if ((a->flag.z_flg) && a->precision == -1)
		*zeros = *spaces;
	if (a->flag.n_flg == 0)
		put_chr_n(' ', *spaces - *zeros);

	if (neg)
		put_chr_n('-', 1);
	else if (a->flag.p_flg)
		put_chr_n('+', 1);
	put_chr_n('0', *zeros);
	ft_putstr(&print_res[neg]);
		free(print_res);
	//printf("\nAAAAA%s\n", print_res);
}

int type_di(t_param *a, va_list ap)
{
	int res;
	long long d;
	int spaces;
	int zeros;
	char *str;

	spaces = 0;
	zeros = 0;
	res = 0;
	d = get_di(a, ap);
	//printf("in type_d:%lld\n", d);
	str = ft_itoa_base(d, 10);
	if (a->spaces > 0 && !a->flag.is && d >= 0 && a->width <= a->precision)
		res = put_chr_n(' ', 1);
	type_di_help(a, d, &spaces, &zeros);
	if (a->flag.n_flg)
		put_chr_n(' ', spaces - zeros);
	if (a->flag.p_flg && d >= 0)
		res++;
	res += ft_strlen(str) + ft_max(spaces, zeros);
	free(str);
	if(d == 0 && a->precision == 0)
		res--;
	return (res);
}
