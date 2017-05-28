/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:13:27 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/15 13:42:47 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *s)
{
	char	c;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i < len / 2)
	{
		c = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = c;
		i++;
	}
}

static int	get_size(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 10)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

static int	if_negative(int *n, char *res, int *flag_neg)
{
	int i;

	i = 0;
	if (*n == -2147483648)
	{
		*n = *n / 10;
		res[0] = '8';
		i++;
	}
	if (*n < 0)
	{
		*flag_neg = 1;
		*n = *n * (-1);
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		flag_neg;
	char	*res;
	int		i;

	i = 0;
	flag_neg = 0;
	res = ft_strnew(get_size(n));
	if (!res)
		return (res);
	i = if_negative(&n, res, &flag_neg);
	while (n >= 10)
	{
		if (n % 10 < 10)
		{
			res[i] = n % 10 + '0';
			i++;
		}
		n = n / 10;
	}
	res[i] = n + '0';
	i++;
	if (flag_neg)
		res[i] = '-';
	ft_swap(res);
	return (res);
}
