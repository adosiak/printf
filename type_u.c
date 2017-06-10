/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:42:28 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/09 15:47:33 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

char	*str_toupper(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	return (str);
}

char	*flag_xo_help(t_param *a, int *spaces)
{
	if (a->flag.h_flg)
	{
		if (a->type == 10 || a->type == 11)
		{
			*spaces = *spaces - 2;
			if (a->type == 10)
				return ("0x");
			else
				return ("0X");
		}
		if (a->type == 6 || a->type == 7)
		{
			*spaces = *spaces - 1;
			return ("0");
		}
	}
	return (0);
}

char	*get_printres(t_param *a, unsigned long long int d, int *res_len)
{
	char *print_res;

	if (a->type == 6 || a->type == 7)
		print_res = unsign_itoa_base(d, 8);
	else if (a->type == 8 || a->type == 9)
		print_res = unsign_itoa_base(d, 10);
	else if (a->type == 10 || a->type == 11)
		print_res = unsign_itoa_base(d, 16);
	if (d == 0 && (a->precision == 0 || (a->flag.h_flg && a->type < 10)))
		print_res = 0;
	*res_len = ft_strlen(print_res);
	return (print_res);
}

char	*type_uox_help(t_param *a, unsigned long long int d, int *spaces,
	int *zeros)
{
	int		res_len;
	char	*print_res;
	char	*print_x_flag;

	res_len = 0;
	print_res = get_printres(a, d, &res_len);
	*spaces = a->width - res_len;
	if (a->precision >= res_len)
		*zeros = a->precision - res_len;
	if (d == 0 && a->flag.h_flg && a->precision == -1)
		(*spaces)++;
	print_x_flag = flag_xo_help(a, spaces);
	if (a->flag.z_flg && a->precision == -1)
		*zeros = *spaces;
	if (a->flag.n_flg == 0)
		put_chr_n(' ', *spaces - *zeros);
	if (!(d == 0 && (a->type == 10 || a->type == 11)))
		ft_putstr(print_x_flag);
	put_chr_n('0', *zeros);
	if (a->type == 11)
		ft_putstr(str_toupper(print_res));
	else
		ft_putstr(print_res);
	return (print_res);
}

int		type_uox(t_param *a, va_list ap)
{
	int						res;
	unsigned long long int	d;
	int						spaces;
	int						zeros;
	char					*print_res;

	spaces = 0;
	zeros = 0;
	res = 0;
	d = get_uox(a, ap);
	if (a->flag.n_flg)
		a->flag.z_flg = 0;
	print_res = type_uox_help(a, d, &spaces, &zeros);
	if (a->flag.n_flg)
		put_chr_n(' ', spaces - zeros);
	if (a->flag.h_flg && (d > 0 || (a->type == 6 || a->type == 7)))
	{
		if (a->type == 10 || a->type == 11)
			res += 2;
		if (a->type == 6 || a->type == 7)
			res += 1;
	}
	res += ft_strlen(print_res) + ft_max(spaces, zeros);
	free(print_res);
	return (res);
}
