/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:39:58 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/29 16:59:21 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**ft_freepipes(t_pipex *vars)
{
	int	i;
	int	**pipes;

	closepipes(vars);
	pipes = vars->pipes;
	i = 0;
	while (pipes[i])
		free(pipes[i++]);
	free(pipes);
	return (NULL);
}

int	**ft_justfreepipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
		free(pipes[i++]);
	free(pipes);
	return (NULL);
}

int	**ft_getpipes(int count)
{
	int	**rtn;
	int	i;

	rtn = (int **)malloc(sizeof(int *) * (count + 1));
	if (!rtn)
		return (errno = ENOMEM, NULL);
	i = 0;
	while (i < count)
	{
		rtn[i] = (int *)malloc(sizeof(int) * 2);
		if (!(rtn[i]))
			return (errno = ENOMEM, ft_justfreepipes(rtn));
		if (pipe(rtn[i]) == -1)
			return (ft_justfreepipes(rtn));
		i++;
	}
	return (rtn[i] = 0, rtn);
}
