/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startforking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:18:40 by yrhiba            #+#    #+#             */
/*   Updated: 2022/12/06 03:43:36 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wichfds(int *rw, t_pipex *vars, int *fds, int i)
{
	if ((i != 0) && (i != (vars->cmds_count - 1)))
	{
		rw[0] = ((vars->pipes)[i][0]);
		rw[1] = ((vars->pipes)[i + 1][1]);
	}
	else if (i == 0)
	{
		rw[0] = fds[0];
		rw[1] = ((vars->pipes)[i + 1][1]);
	}
	else if (i == (vars->cmds_count - 1))
	{
		rw[0] = ((vars->pipes)[i][0]);
		rw[1] = fds[1];
	}
}

int	startproc(int *rw, t_pipex *vars, int *fds, int i)
{
	wichfds(rw, vars, fds, i);
	if (dup2(rw[1], STDOUT_FILENO) == -1 || dup2(rw[0], STDIN_FILENO) == -1)
		return (closeallfds(vars, fds), free(vars->pids),
			perror("error 50(startforking)"), 1);
	closeallfds(vars, fds);
	vars->args = getcmdargs(vars, vars->av, vars->ev, i);
	if (!(vars->args))
		return (free(vars->pids), perror("error 56(startforking)"), 1);
	if (execve((vars->args)[0], vars->args, (char *const *)vars->ev) == -1)
		return (free(vars->pids), free(vars->args),
			perror("error 55(startforking)"), 1);
	return (1);
}

int	startforking(t_pipex *vars, const char **av, const char **ev, int *fds)
{
	int	i;
	int	rw[2];

	vars->pids = (int *)malloc(sizeof(int) * vars->cmds_count);
	if (!(vars->pids))
		return (perror("error 20(startforking)"), 1);
	i = -1;
	while (++i < vars->cmds_count)
	{
		(vars->pids)[i] = fork();
		if ((vars->pids)[i] == -1)
			return (free(vars->pids), perror("error 50(startforking)"), 1);
		if (((vars->pids)[i]) == 0)
		{
			vars->av = av;
			vars->ev = ev;
			startproc(rw, vars, fds, i);
			return (1);
		}
	}
	return (free(vars->pids), 0);
}
