/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:13:03 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/14 11:49:11 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *tmp_lst;
	t_list *tmp_fresh;
	t_list *tmp;

	if (!lst)
		return (NULL);
	tmp_lst = lst;
	tmp = f(tmp_lst);
	fresh = ft_lstnew(tmp->content, tmp->content_size);
	if (!fresh)
		return (NULL);
	tmp_fresh = fresh;
	while (tmp_lst->next)
	{
		tmp_lst = tmp_lst->next;
		tmp = f(tmp_lst);
		fresh->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!fresh->next)
			return (NULL);
		fresh = fresh->next;
	}
	return (tmp_fresh);
}
