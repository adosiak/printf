/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:48:57 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/14 12:05:26 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c && (s[i - 1] == c || i == 0))
			count++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] && s[i] == c && s[i - 1] != c)
			continue;
	}
	return (count);
}

static int	get_word(const char *s, char c, int *j)
{
	int i;
	int count;

	i = *j;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c && (s[i - 1] == c || i == 0))
		{
			while (s[i] && s[i] != c)
			{
				count++;
				i++;
			}
			*j = i;
			break ;
		}
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		n;
	int		i;
	int		j;
	int		len;
	char	**res;

	i = 0;
	j = 0;
	len = 0;
	if (!s)
		return (NULL);
	n = get_size(s, c);
	res = (char **)malloc(sizeof(*res) * (n + 1));
	if (!res)
		return (NULL);
	res[n] = NULL;
	while (i < n)
	{
		j = j + len;
		len = get_word(s, c, &j);
		j = j - len;
		res[i] = ft_strsub(s, j, len);
		i++;
	}
	return (res);
}
