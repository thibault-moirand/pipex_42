/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:14:38 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 17:14:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (element_size == 0 || num_elements == 0)
	{
		num_elements = 1;
		element_size = 1;
	}
	str = (char *)malloc(element_size * num_elements);
	if (str == NULL)
		return (NULL);
	while (i < element_size * num_elements)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

size_t	cworld(char const *s, char c)
{
	int		i;
	size_t	nbm;

	i = 0;
	nbm = 0;
	if (s[0] == '\0' || s == NULL || !s || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			nbm++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (nbm);
}

size_t	countsize(char const *s, char c, int i)
{
	size_t	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**splite;
	int		k;
	int		i;
	int		j;

	k = 0;
	i = 0;
	splite = (char **)ft_calloc(cworld(s, c) + 1, sizeof(char *));
	if (splite == NULL)
		return (NULL);
	while ((cworld(s, c) - k) > 0)
	{
		while (s[i] == c)
			i++;
		j = 0;
		splite[k] = (char *)ft_calloc(countsize(s, c, i) + 1, sizeof(char));
		if (splite[k] == NULL)
			return (NULL);
		while (s[i] != c && s[i])
			splite[k][j++] = s[i++];
		splite[k++][j] = '\0';
	}
	return (splite);
}

char	**ft_split2(char const *s, char c)
{
	char	**splite;
	int		k;
	int		i;
	int		j;

	k = 0;
	i = 5;
	splite = (char **)ft_calloc(cworld(s, c) + 1, sizeof(char *));
	if (splite == NULL)
		return (NULL);
	while ((cworld(s, c) - k) > 0)
	{
		while (s[i] == c)
			i++;
		j = 0;
		splite[k] = (char *)ft_calloc(countsize(s, c, i) + 2, sizeof(char));
		if (splite[k] == NULL)
			return (NULL);
		while (s[i] != c && s[i])
			splite[k][j++] = s[i++];
		splite[k][j++] = '/';
		splite[k++][j] = '\0';
	}
	return (splite);
}
