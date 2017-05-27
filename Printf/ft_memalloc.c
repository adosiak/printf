/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:54:15 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/26 18:35:58 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memalloc(size_t size)
{
	void *fmem;

	fmem = (void *)malloc(sizeof(*fmem) * size);
	if (!fmem)
		return (NULL);
	ft_memset(fmem, '\0', size);
	return (fmem);
}
