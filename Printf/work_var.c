/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:26:24 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/26 19:00:12 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		work_var(t_param *a, va_list ap)
{
	int res;
	res = 0;
	if (a->type == 0)
		res = type_s(a, ap);
	if (a->type == 2)
		type_p(a, ap);
	if (a->type == 3)
		type_d(a, ap);
	ft_putstr(a->extra);
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

int		type_s(t_param *a, va_list ap)
{
	char *str;
	char *tmp;
	int i;
	int spaces;
	int res;

	i = -1;
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

void type_d(t_param *a, va_list ap)
{
	int d;
	d = va_arg(ap, int);
	ft_itoa(d);
}
void type_p(t_param *a, va_list ap)
{
	size_t p;
	p = va_arg(ap, size_t);
	//work on ft_itoa_base(change int to unsingned long long?);
	ft_putstr(ft_itoa_base(p, 16));
	//  printf("###\n");
	//printf("\nCorrect:%p\n", &p);

}
