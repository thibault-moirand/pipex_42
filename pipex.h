/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <tmoirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:06:39 by marvin            #+#    #+#             */
/*   Updated: 2024/01/22 12:52:18 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipe
{
	char	**env;
	char	**v1;
	char	**v2;
	int		i;
	int		j;
	int		pipefd[2];
}	t_pipe;

void	*ft_calloc(size_t num_elements, size_t element_size);
size_t	cworld(char const *s, char c);
size_t	countsize(char const *s, char c, int i);
char	**ft_split(char const *s, char c);
char	**ft_split2(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *c1, const char *c2, size_t n);
void	ft_putstr(char *a, t_pipe *pipee);
void	path(t_pipe *pipee);
void	freee(char **a);

#endif
