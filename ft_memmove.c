/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:52:54 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/11 20:49:27 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*csrc;
	char	*copystr;
	size_t	i;

	i = 0;
	csrc = (char *)src;
	copystr = (char *)malloc(n);
	if (!copystr)
		return (dst);
	while (i < n)
	{
		copystr[i] = csrc[i];
		i++;
	}
	ft_memcpy(dst, copystr, n);
	free(copystr);
	return (dst);
}
