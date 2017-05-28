/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:51:26 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/11 21:06:32 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_line_and_extra(char **line, char *tmp_line)
{
	int		extra_len;
	int		tmp_line_len;
	int		pos;
	char	*del;

	extra_len = ft_strlen(ft_strchr(tmp_line, '\n'));
	tmp_line_len = ft_strlen(tmp_line);
	if (tmp_line[0] == '\n')
	{
		del = tmp_line;
		tmp_line = ft_strsub(del, 1, tmp_line_len - 1);
		free(del);
		*line = ft_strdup("");
		return (tmp_line);
	}
	pos = tmp_line_len - extra_len;
	*line = ft_strsub(tmp_line, 0, pos);
	del = tmp_line;
	tmp_line = ft_strsub(del, pos + 1, tmp_line_len - pos - 1);
	free(del);
	return (tmp_line);
}

static t_list	*get_current_list(t_list **list, const int fd)
{
	t_file	my_struct;
	t_list	*tmp_list;

	tmp_list = *list;
	while (tmp_list)
	{
		if (fd == ((t_file *)(tmp_list->content))->fd)
			break ;
		tmp_list = tmp_list->next;
	}
	if (!tmp_list)
	{
		my_struct.fd = fd;
		my_struct.str = ft_memalloc(1);
		my_struct.str[0] = '\0';
		tmp_list = ft_lstnew(&my_struct, sizeof(t_file));
		ft_lstadd(list, tmp_list);
	}
	return (tmp_list);
}

static int		ft_read(int *read_return, t_file **tmp_my, int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*del;

	while ((*read_return = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*read_return] = '\0';
		del = (*tmp_my)->str;
		(*tmp_my)->str = ft_strjoin(del, buf);
		free(del);
		if (ft_strchr(buf, '\n'))
		{
			(*tmp_my)->str = get_line_and_extra(line, (*tmp_my)->str);
			return (1);
		}
	}
	return (0);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_file			*tmp_my;
	t_list			*tmp_list;
	char			buf[BUFF_SIZE + 1];
	int				read_return;

	if (fd < 0 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	tmp_list = get_current_list(&list, fd);
	tmp_my = tmp_list->content;
	if (ft_strchr(tmp_my->str, '\n'))
	{
		tmp_my->str = get_line_and_extra(line, tmp_my->str);
		return (1);
	}
	if (ft_read(&read_return, &tmp_my, fd, line) == 1)
		return (1);
	if (read_return == 0 && ft_strlen(tmp_my->str) > 0)
	{
		*line = ft_strdup(tmp_my->str);
		ft_strclr(tmp_my->str);
		return (1);
	}
	return (0);
}
