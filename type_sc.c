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
	//printf("\nstr=%s\n", str);
	spaces = 0;
	// if ( a->length == l) and argument is not *int or wchar_t, warning is generated
	// if (a->flag == "+, #, 0") undefined behavior

	if (!str)
		str = "(null)";
	else if (str[0] && a->precision != -1)
		spaces = a->width - a->precision;
	else
		spaces = a->width - ft_strlen(str);
	//printf("1.spaces:%d\nwidth=%i\n", spaces, a->width);

	if (a->flag.n_flg == 0)
		put_chr_n(' ', spaces);
	res = ft_strlen(str);
//printf("reshere:%d\n", res);

	if (a->precision == -1)
		ft_putstr(str);
	else
	{
		//	printf("\n!!!rpres=%d", a->precision);
		tmp = ft_strsub(str, 0, a->precision);
		if(str[0])
			res = a->precision;
		ft_putstr(tmp);
		free(tmp);
	}
	if (a->flag.n_flg == 1)
		put_chr_n(' ', spaces);
	if (spaces > 0)
		res = res + spaces;
	//printf("\n!!!res=%d", res);
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

	if (a->flag.n_flg == 0)
		put_chr_n(' ', spaces);
	ft_putchar(c);

	if (a->flag.n_flg == 1)
		put_chr_n(' ', spaces);
	res = res + spaces;
  return(res);
}

int no_type(t_param *a)
{
  int res;
	int spaces;
  res = 0;
	spaces = 0;
	int new_start;
	// if ( a->length == l) and argument is not *int or wchar_t, warning is generated
	// if (a->flag == "+, #, 0") undefined behavior
	spaces = a->width - 1;
	new_start = ft_strchr0(a->extra, 0, '%');
//	printf("new_start=%d, old extra=%s", new_start, a->extra);
	if (new_start > 0)
		ft_memmove(&a->extra[0], &a->extra[new_start], ft_strlen(a->extra) - new_start + 1);

	//printf("\nnew extra=%s\n", a->extra);

	if (a->flag.n_flg == 0)
		put_chr_n(' ', spaces);
	ft_putchar(a->extra[0]);
	if (a->flag.n_flg == 1)
		put_chr_n(' ', spaces);

	if (a->extra[1])
		ft_putstr(&(a->extra[1]));
	if (spaces > 0)
		res = spaces;
  return(res);
}
