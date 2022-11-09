/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:35:18 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/09 18:10:05 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_clear(t_map *head, char **line, char **var)
{
	t_map	*next;

	if (head)
	{
		while (head)
		{
			next = head->next;
			free(head);
			head = next;
		}
	}
	if (line)
		ft_free_split(line);
	if (var)
		ft_free_split(var);
}

static t_map	*rmhelper(t_rm *rm)
{
	if ((*rm).var)
		ft_free_split((*rm).var);
	(*rm).var = ft_split((*rm).line[(*rm).i], ',');
	if (!(*rm).var)
		return (ft_clear((*rm).head, (*rm).line, (*rm).var), NULL);
	(*rm).next = ft_calloc(1, sizeof(t_map));
	if (!(*rm).next)
		return (ft_clear((*rm).head, (*rm).line, (*rm).var), NULL);
	(*rm).next->y = ft_atoi((*rm).var[0]) * 10;
	if ((*rm).var[1])
		(*rm).next->color.pixel = (unsigned int)ft_xtoi((*rm).var[1]);
	if (!(*rm).head)
		(*rm).head = (*rm).next;
	if ((*rm).node)
	{
		if ((*rm).topnode)
			(*rm).topnode->down = (*rm).next;
		if ((*rm).topnode)
			(*rm).topnode = (*rm).topnode->next;
		if ((*rm).i != 0)
			(*rm).node->right = (*rm).next;
		(*rm).node->next = (*rm).next;
	}
	return ((*rm).head);
}

static void	rmhelper2(t_rm *rm)
{
	ft_free_split((*rm).line);
	(*rm).line = ft_better_split(ft_better_trim(
				get_next_line((*rm).fd), " \t\n\v\f\r"), ' ');
	if ((*rm).topnode == NULL)
		(*rm).topnode = (*rm).head;
}

t_map	*read_map(int fd)
{
	t_rm	rm;

	rm.fd = fd;
	rm.node = NULL;
	rm.next = NULL;
	rm.topnode = NULL;
	rm.head = NULL;
	rm.var = NULL;
	rm.line = ft_better_split(ft_better_trim(get_next_line(fd), " \t\v\f\n\r"), ' ');
	if (!rm.line)
		return (NULL);
	while (rm.line)
	{
		rm.i = 0;
		while (rm.line[rm.i])
		{
			if (!rmhelper(&rm))
				return (NULL);
			rm.node = rm.next;
			rm.i++;
		}
		rmhelper2(&rm);
	}
	ft_free_split(rm.var);
	return (rm.head);
}
