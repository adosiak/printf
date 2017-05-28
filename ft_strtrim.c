/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:39:57 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/15 13:02:24 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_valid(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	char			*fresh;
	unsigned int	i;
	unsigned int	start_index;
	unsigned int	end_index;
	int				flag;

	i = 0;
	flag = if_valid(s);
	if (flag)
		return (ft_strnew(0));
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	start_index = i;
	i = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	end_index = i;
	fresh = ft_strsub(s, start_index, end_index - start_index + 1);
	if (!fresh)
		return (NULL);
	return (fresh);
}
