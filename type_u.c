/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:42:28 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/29 17:42:33 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

char *type_u_help(t_param *a, int d, int *spaces, int *zeros)
{
  int res_len;
  char *print_res;


  if (a->type == 6)
    print_res = ft_itoa_base(d, 8);
  else if (a->type == 8)
    print_res = ft_itoa_base(d, 10);
  else if (a->type == 10)
    print_res = ft_itoa_base(d, 16);
  res_len = ft_strlen(print_res);

	if(d == 0 && a->precision == 0)
		print_res = 0;
	if (a->width > 0 && a->width >= res_len)
		*spaces = a->width - res_len;
	if (a->precision != -1 && (a->precision >= res_len))
		*zeros = a->precision - res_len;
	if ((a->flag && ft_strcmp(a->flag, "0") == 0) && a->precision == -1)
		*zeros = *spaces;

	if (!a->flag || ft_strcmp(a->flag, "-") != 0)
		put_chr_n(' ', *spaces - *zeros);
	put_chr_n('0', *zeros);
	ft_putstr(print_res);
  return (print_res);
}

int type_u(t_param *a, va_list ap)
{
	int res;
	unsigned int d;
	int spaces;
	int zeros;
  char *print_res;


	spaces = 0;
	zeros = 0;
	res = 0;
	d = va_arg(ap, int);


	print_res = type_u_help(a, d, &spaces, &zeros);

	if (a->flag && ft_strcmp(a->flag, "-") == 0)
		put_chr_n(' ', spaces - zeros);

	res += ft_strlen(print_res) + ft_max(spaces, zeros);
	if(d == 0 && a->precision == 0)
		res--;
	return (res);
}
