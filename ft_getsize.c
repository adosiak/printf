/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:35:42 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/23 17:02:41 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getsize(int value, int base)
{
	int i;

	i = 0;
	if (value < 0)
		value = value * (-1);
	while (value >= base)
	{
		i++;
		value = value / base;
	}
	if (base > 9)
		return (i + 1);
	else
		return (i);
}
