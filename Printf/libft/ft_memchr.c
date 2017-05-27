/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:32:13 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/12 00:24:36 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	size_t			i;
	unsigned char	uc;

	i = 0;
	cs = (unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (cs[i] == uc)
			return (&cs[i]);
		i++;
	}
	return (NULL);
}
