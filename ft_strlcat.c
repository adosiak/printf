/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:21:43 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/15 13:07:45 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if ((len_dst < (n - 1)) && n > 0)
	{
		while ((i + len_dst) < (n - 1))
		{
			dst[i + len_dst] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}
	if (len_dst > n)
		return (n + len_src);
	else
		return (len_dst + len_src);
}
