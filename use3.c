/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:26:30 by marvin            #+#    #+#             */
/*   Updated: 2024/01/19 12:26:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freee(char **a)
{
	int	i;

	i = -1;
	while (a[++i])
		free(a[i]);
	free (a);
}

void	path(t_pipe *pipee)
{
	int	i;

	i = -1;
	while (pipee->v1[++i])
		free(pipee->v1[i]);
	free (pipee->v1);
	i = -1;
	while (pipee->v2[++i])
		free(pipee->v2[i]);
	free (pipee->v2);
	i = -1;
	while (pipee->env[++i])
		free(pipee->env[i]);
	free (pipee->env);
}
