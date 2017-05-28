/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:43:38 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/11 20:54:05 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		if (i == len)
			return (dest);
		dest[i] = src[i];
		i++;
	}
	if (len > i)
	{
		while (len > i)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
