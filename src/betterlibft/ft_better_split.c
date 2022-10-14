/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:54:25 by peter             #+#    #+#             */
/*   Updated: 2022/04/18 19:28:01 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftio.h>

static int	ft_getelen(char const *src, char c)
{
	int	total;
	int	i;

	total = 1;
	i = 0;
	while (src[i])
	{
		if (src[i] == c && src[i + 1] != c)
			total++;
		i++;
	}
	return (total);
}

static int	ft_free(char **cache, int j)
{
	if (!cache[j])
	{
		while (j >= 0)
		{
			free(cache[j]);
			j--;
		}
		free(cache);
		return (0);
	}
	return (1);
}

static char	**ft_splitting(char **cache, char const *src, char c)
{
	size_t	i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	while (src[i])
	{
		len = 0;
		while (src[i] && src[i] != c)
		{
			i++;
			len++;
		}
		if ((src[i] == c && i) || (!src[i] && (src[ft_strlen(src) - 1] != c)))
		{
			cache[j++] = ft_substr(src, i - len, len);
			if (!ft_free(cache, j - 1))
				return (NULL);
		}
		while (src[i] && src[i] == c)
			i++;
	}
	cache[j] = NULL;
	return (cache);
}

char	**ft_better_split(char *src, char c)
{
	char	**cache;

	if (!src)
		return (NULL);
	cache = ft_calloc(sizeof(char *) * (ft_getelen(src, c) + 1), 1);
	if (!cache)
		return (NULL);
	if (*src == '\0' && ft_strlen(src) == 0)
		*cache = (NULL);
	else
		cache = ft_splitting(cache, src, c);
	free(src);
	return (cache);
}
