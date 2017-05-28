/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:30:31 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/11 20:52:47 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *copystr;

	copystr = (char *)malloc(sizeof(*copystr) * (ft_strlen(str) + 1));
	if (!copystr)
		return (NULL);
	return (ft_strcpy(copystr, str));
}
