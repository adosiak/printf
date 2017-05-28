/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:33:15 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/10 14:56:23 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*fresh;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	fresh = (ft_strnew(s1_len + s2_len));
	if (!fresh)
		return (NULL);
	ft_memcpy(fresh, (void *)s1, s1_len);
	ft_strcpy(&fresh[s1_len], s2);
	return (fresh);
}
