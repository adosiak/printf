/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:54:15 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/10 15:53:14 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *fmem;

	fmem = (void *)malloc(sizeof(*fmem) * size);
	if (!fmem)
		return (NULL);
	ft_bzero(fmem, size);
	return (fmem);
}
