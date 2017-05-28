/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:25:17 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/13 19:21:23 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*cdst;
	char	*csrc;
	size_t	i;

	cdst = (char *)dst;
	csrc = (char *)src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == c)
			break ;
		i++;
	}
	if (cdst[i] == c)
		return ((void *)&cdst[i + 1]);
	else
		return (NULL);
}
