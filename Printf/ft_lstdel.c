/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:03:39 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/13 14:54:49 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *buflst;

	buflst = NULL;
	while (*alst)
	{
		buflst = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = buflst;
	}
	alst = NULL;
}
