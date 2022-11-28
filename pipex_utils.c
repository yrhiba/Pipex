/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:42:37 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/28 12:58:41 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_getcmdscount(int herdoc, int ac)
{
	if (!herdoc)
		return (ac - 4);
	return (ac - 3);
}

char **ft_getcmds(t_pipex *vars, char  **av)
{
	if (vars->herdoc)
		return (av + 3);
	return (av + 2);
}

void	closepipes(t_pipex *vars)
{
	int	i;

	i = 0;
	while (i < (vars->cmds_count + 1))
	{
		close(vars->pipes[i][0]);
		close(vars->pipes[i][1]);
	}
}
