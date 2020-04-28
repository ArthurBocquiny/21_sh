/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:39:20 by arbocqui          #+#    #+#             */
/*   Updated: 2019/11/21 11:11:01 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

t_gnl				*ft_lstnew_gnl(void const *content, size_t fd)
{
	t_gnl			*new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->fd = fd;
	}
	else
	{
		if (!(new->content = (void*)malloc(sizeof(void) * ft_strlen(content))))
			return (NULL);
		ft_memcpy(new->content, content, ft_strlen(content));
		new->fd = fd;
	}
	new->next = NULL;
	return (new);
}

void				ft_lstadd_gnl(t_gnl **alst, t_gnl *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_gnl				*ft_listcheck(int fd, t_gnl **list)
{
	t_gnl			*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew_gnl("", fd);
	ft_lstadd_gnl(list, tmp);
	if (ft_strlen(tmp->content) > 0)
		ft_strclr(tmp->content);
	return (tmp);
}

int					ft_tri(char **line, t_gnl *tmp, int ret)
{
	int				i;
	char			*save;

	i = 0;
	save = NULL;
	if (ret < BUFF_SIZE && !ft_strlen(tmp->content))
		return (0);
	while (((char*)tmp->content)[i] != '\n' && ((char*)tmp->content)[i] != '\0')
		i++;
	*line = ft_strsub(tmp->content, 0, i);
	if (i < (int)ft_strlen(tmp->content) - 1)
	{
		save = ft_strdup(tmp->content + i + 1);
		free(tmp->content);
		tmp->content = save;
	}
	else
		ft_strclr(tmp->content);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	t_gnl			*tmp;
	int				ret;
	static	t_gnl	*list;

	ret = 0;
	if (fd < 0 || !line || (read(fd, buf, 0)) < 0)
		return (-1);
	tmp = ft_listcheck(fd, &list);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && fd >= 0 && BUFF_SIZE > 0)
	{
		buf[ret] = '\0';
		tmp->content = ft_strjoinf(tmp->content, buf, 1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ft_tri(line, tmp, ret));
}
