/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:29:39 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/26 18:25:33 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_strrev(char *str)
{
	char	a;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		a = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = a;
		i++;
	}
}
