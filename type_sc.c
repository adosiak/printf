/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:48:35 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/29 17:48:37 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		type_s(t_param *a, va_list ap)
{
	char *str;
	char *tmp;
	//int i;
	int spaces;
	int res;

	//i = -1;
	str = va_arg(ap, char *);

	spaces = 0;
	// if ( a->length == l) and argument is not *int or wchar_t, warning is generated
	// if (a->flag == "+, #, 0") undefined behavior
	if (a->precision != -1)
		spaces = a->width - a->precision;
	else
		spaces = a->width - ft_strlen(str);

	if (!a->flag || ft_strcmp(a->flag, "-") != 0)
		put_chr_n(' ', spaces);
	res = ft_strlen(str);

	if (a->precision == -1)
		ft_putstr(str);
	else
	{
		tmp = ft_strsub(str, 0, a->precision);
		res = a->precision;
		ft_putstr(tmp);
		free(tmp);
	}
	if (a->flag && ft_strcmp(a->flag, "-") == 0)
		put_chr_n(' ', spaces);
	if (spaces > 0)
		res = res + spaces;
	return (res);
}

int type_c(t_param *a, va_list ap)
{
  char c;
  int res;
	int spaces;

	c = va_arg(ap, int);

  res = 1;
	spaces = 0;
	// if ( a->length == l) and argument is not *int or wchar_t, warning is generated
	// if (a->flag == "+, #, 0") undefined behavior
	if (a->width > 1)
		spaces = a->width - 1;

	if (!a->flag || ft_strcmp(a->flag, "-") != 0)
		put_chr_n(' ', spaces);
	ft_putchar(c);

	if (a->flag && ft_strcmp(a->flag, "-") == 0)
		put_chr_n(' ', spaces);
	res = res + spaces;
  return(res);

}
