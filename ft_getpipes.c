/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:39:58 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/28 10:27:22 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**ft_freepipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
		free(pipes[i++]);
	free(pipes);
	return (NULL);
}

int	**ft_getpipes(size_t count)
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
			return (errno = ENOMEM, ft_freepipes(rtn));
		if (pipe(rtn[i]) == -1)
			return (ft_freepipes(rtn));
	}
	return (rtn[i] = 0, rtn);
}
