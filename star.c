/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:09:12 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/08 18:30:50 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

void	handle_star(t_param *a, va_list ap)
{
	int	width;
	int	precision;

	if (a->width == -2)
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			a->flag.n_flg++;
			a->width = width * (-1);
		}
		else
			a->width = width;
	}
	if (a->precision == -2)
		a->precision = va_arg(ap, int);
}