/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startforking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:47:52 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/30 17:48:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	startforking(t_pipex *vars, char **av, char **ev, int *fds)
{
	int	i;

	vars->pids = (int *)malloc(sizeof(int) * vars->cmds_count);
	if (!(vars->pids))
		return (perror("error"), 1);
	i = 0;
	while (i < vars->cmds_count)
	{
		(vars->pids)[i] = fork();
		if ((vars->pids)[i] == -1)
			return (free(vars->pids), perror("error"), (vars->error = 1));
		if (((vars->pids)[i]) == 0)
		{
			if ((i != 0) && (i != (vars->cmds_count - 1)))
			{
				fds[0] = ((vars->pipes)[i][0]);
				fds[1] = ((vars->pipes)[i + 1][1]);
			}
			else if (i == 0)
				fds[0] = ((vars->pipes)[i][0]);
			else if (i == (vars->cmds_count - 1))
				fds[1] = ((vars->pipes)[i + 1][1]);
			if (dup2(fds[1], STDOUT_FILENO) == -1 || dup2(fds[0],
					STDIN_FILENO) == -1)
				return (free(vars->pids), perror("error"), (vars->error = 1));
			vars->args = getcmdargs(vars, av, ev, i);
			if (!(vars->args) || execve((vars->args)[0], vars->args, ev) == -1)
				return (free(vars->pids), free(vars->args), perror("error"),
					(vars->error = 1));
			return (closepipes(vars), 1);
		}
		i++;
	}
	return (free(vars->pids), 0);
}
