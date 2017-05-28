/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:44:36 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/11 21:19:19 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	int_to_char;

	i = ft_strlen(str);
	int_to_char = c;
	while (i >= 0)
	{
		if (str[i] == int_to_char)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
