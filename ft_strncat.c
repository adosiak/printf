/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:19:36 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/11 20:56:06 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str, const char *add, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(str);
	while (add[i] && i < n)
	{
		str[len + i] = add[i];
		i++;
	}
	str[len + i] = '\0';
	return (str);
}
