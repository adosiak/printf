/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_itoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:52:55 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/09 15:53:46 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			unsign_getsize(unsigned long long value, int base)
{
	int i;

	i = 0;
	while (value >= (unsigned long long)base)
	{
		i++;
		value = value / base;
	}
	if (base > 9)
		return (i + 1);
	else
		return (i);
}

static void	put_hex(unsigned long long value, char *str, int i)
{
	if (value < 10)
		str[i] = value + '0';
	else
		str[i] = 'a' + (value - 10);
}

char		*unsign_itoa_base(unsigned long long value, int base)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * unsign_getsize(value, base) + 1);
	i = 0;
	while (value >= (unsigned long long)base)
	{
		put_hex(value % base, str, i);
		i++;
		value = value / base;
	}
	put_hex(value, str, i);
	i++;
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
