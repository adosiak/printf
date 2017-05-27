/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:05:50 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/26 18:24:56 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)ft_memalloc(size + 1);
	if (!str)
		return (NULL);
	ft_strclr(str);
	return (str);
}
