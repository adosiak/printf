/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:27:03 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/02 12:27:06 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int type_p(t_param *a, va_list ap)
{
  unsigned long long p;
  int res;
	int spaces;
  char *str;

	p = (unsigned long long)va_arg(ap, void *);
  str = ft_strjoin("0x", unsign_itoa_base(p, 16));
  res = ft_strlen(str);
	spaces = 0;
	// if (a->flag == "+, #, 0" or width == 0 or length != -1) undefined behavior
	if (a->width > res)
		spaces = a->width - res;

	if (a->flag.n_flg != 1)
		put_chr_n(' ', spaces);
	ft_putstr(str);
	if (a->flag.n_flg == 1)
		put_chr_n(' ', spaces);
	res = res + spaces;
  return(res);

}
