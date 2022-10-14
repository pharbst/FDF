/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:31:43 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/14 15:52:59 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_free_split(char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}

static void	ft_clear(t_map *head, char **line, char **var)
{
	t_map	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
	if (line)
		ft_free_split(line);
	if (var)
		ft_free_split(var);
}

t_map	*ft_get_map(int fd)
{
	t_map			*node;
	t_map			*topnode;
	t_map			*head;
	char			**line;
	char			**var;
	unsigned int	i;

	i = 0;
	head = calloc(1, sizeof(t_map));
	if (!head)
		return (NULL);
	line = ft_better_split(get_next_line(fd), ' ');
	if (!line)
		return (free(head), NULL);
	var = ft_split(line[i], ',');
	if (!var)
		return (ft_free_split(line), free(head), NULL);
	head->y = ft_atoi(var[0]);
	if (var[1])
		head->color.pixel = ft_xtoi(var[1]);
	i++;
	node = head;
	topnode = NULL;
	while (line)
	{
		while (line[i])
		{
			ft_free_split(var);
			var = ft_split(line[i], ',');
			if (!var)
				return (ft_clear(head, line, var), NULL);
			node->next = ft_calloc(1, sizeof(t_map));
			if (!node->next)
				return (ft_clear(head, line, var), NULL);
			if (topnode)
				topnode->down = node->next;
			if (line[i + 1])
				node->right = node->next;
			else
				node->right = NULL;
			node = node->next;
			node->y = ft_atoi(var[0]);
			if (var[1])
				node->color.pixel = ft_xtoi(var[1]);
			if (topnode)
				topnode = topnode->next;
			i++;
		}
		ft_free_split(line);
		line = ft_better_split(get_next_line(fd), ' ');
		if (topnode == NULL)
			topnode = head;
		i = 0;
	}
	return (head);
}
