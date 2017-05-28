/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:56:38 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/11 21:00:53 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *large, const char *small)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (ft_strlen(small) == 0)
		return ((char *)large);
	while (large[i])
	{
		if (large[i] == small[0])
		{
			j = 0;
			k = i;
			while (large[k] == small[j])
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
