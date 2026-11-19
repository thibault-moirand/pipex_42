/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <tmoirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:09:43 by marvin            #+#    #+#             */
/*   Updated: 2024/01/22 12:50:51 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(char **av, t_pipe *pipee, char **envp)
{
	int	fd;

	fd = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	dup2(fd, 1);
	dup2(pipee->pipefd[0], 0);
	close(pipee->pipefd[1]);
	execve(ft_strjoin(pipee->env[pipee->j], pipee->v2[0]), pipee->v2, envp);
	close(fd);
	close(pipee->pipefd[0]);
	close(pipee->pipefd[1]);
	ft_putstr("execve", pipee);
}

void	child(char **av, t_pipe *pipee, char **envp)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_putstr("file", pipee);
	dup2(fd, 0);
	dup2(pipee->pipefd[1], 1);
	close(pipee->pipefd[0]);
	execve(ft_strjoin(pipee->env[pipee->i], pipee->v1[0]), pipee->v1, envp);
	close(fd);
	close(pipee->pipefd[0]);
	close(pipee->pipefd[1]);
	ft_putstr("execve", pipee);
}

void	seearsh(t_pipe *pipee)
{
	char	*temp;

	while (pipee->env[pipee->i] != NULL)
	{
		temp = ft_strjoin(pipee->env[pipee->i], pipee->v1[0]);
		if (access(temp, X_OK) >= 0)
			break ;
		pipee->i++;
		free(temp);
		temp = NULL;
	}
	if (pipee->env[pipee->i] == NULL)
		ft_putstr("PATH1", pipee);
	while (pipee->env[pipee->j] != NULL)
	{
		free(temp);
		temp = NULL;
		temp = ft_strjoin(pipee->env[pipee->j], pipee->v2[0]);
		if (access(temp, X_OK) >= 0)
			break ;
		pipee->j++;
	}
	free(temp);
	if (pipee->env[pipee->j] == NULL)
		ft_putstr("PATH2", pipee);
}

void	pipex2(t_pipe *pipee, char **av, char **envp)
{
	int	i;

	i = 0;
	if (pipe(pipee->pipefd) == -1)
		ft_putstr("pipe", pipee);
	pipee->v1 = ft_split(av[2], ' ');
	pipee->v2 = ft_split(av[3], ' ');
	while (envp[i] != NULL)
	{
		if ((ft_strncmp(envp[i], "PATH=", 5)) == 0)
		{
			pipee->env = ft_split2(envp[i], ':');
			break ;
		}
		i++;
	}
	if (envp[i] == NULL)
		ft_putstr("NO_PATH", pipee);
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	*pipee;
	pid_t	pid1;

	pipee = malloc(sizeof(t_pipe));
	pipee->i = 0;
	pipee->j = 0;
	if (ac != 5)
		return (ft_putstr("ac", pipee), 1);
	if (access(av[1], R_OK) < 0)
		return (ft_putstr("file", pipee), 1);
	pipex2(pipee, av, envp);
	seearsh(pipee);
	pid1 = fork();
	if (pid1 == -1)
		return (ft_putstr("fork", pipee), 1);
	if (pid1 == 0)
		child(av, pipee, envp);
	parent (av, pipee, envp);
	exit(1);
}
