/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:35:18 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/03 16:24:44 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_free_split(char **src)
{
	int	i;

	i = 0;
	if (!src)
		return ;
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

t_map	*read_map(int fd)
{
	unsigned int	i;
	t_map			*head;
	t_map			*node;
	t_map			*next;
	t_map			*topnode;
	char			**line;
	char			**var;

	node = NULL;
	next = NULL;
	topnode = NULL;
	head = NULL;
	var = NULL;

	line = ft_better_split(ft_better_trim(get_next_line(fd), " \t\v\f\n\r"), ' ');
	if (!line)
		return (NULL);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if(var)
				ft_free_split(var);
			var = ft_split(line[i], ',');
			if (!var)
				return (ft_clear(head, line, var), NULL);
			next = ft_calloc(1, sizeof(t_map));
			if (!next)
				return (ft_clear(head, line, var), NULL);
			next->y = ft_atoi(var[0]);
			if (var[1])
				next->color.pixel = (unsigned int)ft_xtoi(var[1]);
			if (!head)
				head = next;
			if (node)
			{
				if (topnode)
					topnode->down = next;
				if (topnode)
					topnode = topnode->next;
				if (i != 0)
					node->right = next;
				node->next = next;
			}
			node = next;
			i++;
		}
		ft_free_split(line);
		line = ft_better_split(ft_better_trim(get_next_line(fd), " \t\n\v\f\r"), ' ');
		if (topnode == NULL)
			topnode = head;
	}
	return (head);
}
