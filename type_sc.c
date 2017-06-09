/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:48:35 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/08 19:29:10 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		get_spaces_s(char *str, t_param *a)
{
	int		spaces;

	spaces = 0;
	if (!str)
		str = "(null)";
	else if (str[0] && a->precision != -1)
		spaces = a->width - a->precision;
	else
		spaces = a->width - ft_strlen(str);
	return (spaces);
}

int		get_spaces_ls(wchar_t *str, t_param *a, int i)
{
	int		spaces;

	spaces = 0;
	if (!str)
		str = L"(null)";
	else if (str[0] && a->precision != -1)
		spaces = a->width - a->precision;
	else
		spaces = a->width - i;
	return (spaces);
}

int		type_ls(t_param *a, va_list ap)
{
	wchar_t	*str;
	int		spaces;
	int		res;
	int		i;
	int		len;

	i = 0;
	str = va_arg(ap, wchar_t *);
	while (str[i])
		i++;
	spaces = get_spaces_ls(str, a, i);
	if (a->flag.n_flg == 0)
		put_chr_n(' ', spaces);
	if (a->precision == -1)
		len = i;
	else
		len = a->precision;
	i = -1;
	while (++i < len)
		write(1, &str[i], 1);
	if (a->flag.n_flg)
		put_chr_n(' ', spaces);
	res = len + ft_max(spaces, 0);
	return (res);
}

int		type_s(t_param *a, va_list ap)
{
	char	*str;
	int		spaces;
	int		res;

	if (a->length == 2 || a->type == 1)
		return (type_ls(a, ap));
	str = va_arg(ap, char *);
	spaces = 0;
	if (!str)
		str = "(null)";
	else if (str[0] && a->precision != -1)
		spaces = a->width - a->precision;
	else
		spaces = a->width - ft_strlen(str);
	//printf("aaa:%s\n", str);
//	spaces = get_spaces_s(str, a);
	if (a->flag.n_flg == 0)
		put_chr_n(' ', spaces);
	res = ft_strlen(str);
	if (a->precision == -1)
		ft_putstr(str);
	else
	{
		ft_putfree(ft_strsub(str, 0, a->precision));
		if (str[0])
			res = a->precision;
	}
	if (a->flag.n_flg)
		put_chr_n(' ', spaces);
	if (spaces > 0)
		res = res + spaces;
	return (res);
}

int		type_c(t_param *a, va_list ap)
{
	char	c;
	int		res;
	int		spaces;

	c = va_arg(ap, int);
	res = 1;
	spaces = 0;
	if (a->width > 1)
		spaces = a->width - 1;
	if (a->flag.n_flg == 0)
		put_chr_n(' ', spaces);
	ft_putchar(c);
	if (a->flag.n_flg)
		put_chr_n(' ', spaces);
	res = res + spaces;
	return (res);
}

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
