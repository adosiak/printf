/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 09:04:48 by exam              #+#    #+#             */
/*   Updated: 2017/03/14 15:40:48 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_hex(int value, char *str, int i)
{
	if (value < 10)
		str[i] = value + '0';
	else
		str[i] = 'A' + (value - 10);
}

static void	neg_strend(char *str, int i, int flag, int base)
{
	if (base == 10 && flag)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;
	int		flag;

	str = (char *)malloc(sizeof(char) * ft_getsize(value, base) + 1);
	i = 0;
	flag = 0;
	if (value == -2147483648)
		return ("-2147483648");
	if (value < 0)
	{
		value = value * (-1);
		flag = 1;
	}
	while (value >= base)
	{
		put_hex(value % base, str, i);
		i++;
		value = value / base;
	}
	put_hex(value, str, i);
	i++;
	neg_strend(str, i, flag, base);
	ft_strrev(str);
	return (str);
}
