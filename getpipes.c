/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:35:45 by yrhiba            #+#    #+#             */
/*   Updated: 2022/12/05 23:24:28 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**freepipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
		free(pipes[i++]);
	free(pipes);
	return (NULL);
}

void	closepipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

int	**getpipes(size_t count)
{
	int		**rtn;
	size_t	i;

	rtn = (int **)malloc(sizeof(int *) * (count + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (i < count)
	{
		rtn[i] = (int *)malloc(sizeof(int) * 2);
		if (!(rtn[i]))
			return (freepipes(rtn));
		if (pipe(rtn[i]) == -1)
			return (rtn[i + 1] = 0, closepipes(rtn), freepipes(rtn));
		i++;
	}
	return (rtn[i] = 0, rtn);
}
