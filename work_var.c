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
	if (a->type == 0)
		res = type_s(a, ap);
	//if (a->type == 2)
//		res = type_p(a, ap);
	if (a->type == 3 || a->type == 5)
		res = type_d(a, ap);
	if (a->type == 8 || a->type == 6 || a->type == 10)
		res = type_u(a, ap);
	if (a->type == 12)
		res = type_c(a, ap);
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

/*void type_p(t_param *a, va_list ap)
{
	size_t p;
	p = va_arg(ap, size_t);
	//work on ft_itoa_base(change int to unsingned long long?);
	ft_putstr(ft_itoa_base(p, 16));
	//  printf("###\n");
	//printf("\nCorrect:%p\n", &p);

}*/
