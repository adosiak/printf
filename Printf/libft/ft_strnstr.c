/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:00:02 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/11 21:02:08 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *large, const char *small, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (ft_strlen(small) == 0)
		return ((char*)large);
	while (large[i] && i < n)
	{
		if (large[i] == small[0])
		{
			j = 0;
			k = i;
			while (large[k] == small[j] && k < n)
			{
				if (j == (ft_strlen(small) - 1))
					return ((char *)&large[k - j]);
				k++;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
