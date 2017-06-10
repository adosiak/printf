/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:51:23 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/09 15:59:49 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		ft_putfree(char *str)
{
	int len;

	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
