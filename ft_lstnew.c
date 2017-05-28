/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 21:42:18 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/15 13:45:35 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	cont_null(t_list *fresh_lst)
{
	fresh_lst->content = NULL;
	fresh_lst->content_size = 0;
	fresh_lst->next = NULL;
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh_lst;
	size_t	c_content_size;

	fresh_lst = (t_list *)malloc(sizeof(t_list));
	if (!fresh_lst)
		return (NULL);
	fresh_lst->content = ft_memalloc(content_size);
	if (!fresh_lst->content)
	{
		free(fresh_lst);
		return (NULL);
	}
	c_content_size = content_size;
	if (content == NULL)
		cont_null(fresh_lst);
	else
	{
		ft_memcpy(fresh_lst->content, content, content_size);
		fresh_lst->content_size = c_content_size;
		fresh_lst->next = NULL;
	}
	return (fresh_lst);
}
