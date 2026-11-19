/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:14:32 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 17:14:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*concat;

	i = 0;
	j = 0;
	concat = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (concat == NULL)
		return (NULL);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}

int	ft_strncmp(const char *c1, const char *c2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (0);
	while (i < n && c1[i] == c2[i] && c1[i] && c2[i])
		i++;
	if (i == n)
		return (0);
	return (1);
}

void	nopath(t_pipe *pipee)
{
	int	i;

	i = 0;
	while (pipee->v1[i])
	{
		free(pipee->v1[i]);
		i++;
	}
	free (pipee->v1);
	i = 0;
	while (pipee->v2[i])
	{
		free(pipee->v2[i]);
		i++;
	}
	free (pipee->v2);
}

void	ft_putstr(char *a, t_pipe *pipee)
{
	int	i;

	i = 0;
	while (a[i])
	{
		write(2, &a[i], 1);
		i++;
	}
	write(2, "\n", 1);
	if ((ft_strncmp(a, "NO_PATH", 7)) == 0)
		nopath(pipee);
	if ((ft_strncmp(a, "PATH1", 5)) == 0 || (ft_strncmp(a, "PATH2", 5)) == 0)
		path(pipee);
	if ((ft_strncmp(a, "execve", 5)) == 0)
		path(pipee);
	free (pipee);
	exit(1);
}
