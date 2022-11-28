/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:13:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/28 13:16:38 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_writetopipe(t_pipex *vars)
{
	size_t	size;

	size = ft_strlen(vars->instr) + 1;
	if (write((vars->pipes)[0][1], &size, sizeof(size_t)) == -1)
		return (1);
	if (wirte((vars->pipes)[0][1], vars->instr, (size * sizeof(char))) == -1)
		return (1);
	return (0);
}

int	ft_startforking(t_pipex *vars, char *av, char const *ev)
{
	int	i;

	vars->pids = (int *)malloc(sizeof(int) * vars->cmds_count);
	if (!(vars->pids))
		return (errno = ENOMEM, perror("error"), 1);
	i = 0;
	while (i < vars->cmds_count)
	{
		(vars->pids)[i] = fork();
		if ((vars->pids)[i] == -1 || vars->error)
			return (free(vars->pids), perror("error"), (vars->error = 1));
		if ((vars->pids)[i] == 0)
		{
			if (dup2((vars->pipes)[i + 1][1], STDOUT_FILENO) == -1 ||
				dup2((vars->pipes)[i][0], STDIN_FILENO) == -1)
				return (free(vars->pids), perror("error"), (vars->error = 1));
			execve(getcmdpath(vars, av, ev), getcmdargs(vars, av, ev), ev);
			return (1);
		}
		i++;
	}
	return (free(vars->pids), 0);
}

int	main(int ac, char const *av[], char const *ev[])
{
	t_pipex	*vars;

	vars->error = 0;
	vars->instr = ft_getinstr(ac, (char **)av, vars);
	if (!(vars->instr))
		return (perror("error"), errno);
	vars->cmds_count = ft_getcmdscount(vars->herdoc, ac);
	vars->pipes = ft_getpipes(vars->cmds_count + 1);
	if (!vars->pipes)
		return (free(vars->instr), perror("error"), errno);
	if (ft_writetopipe(vars))
		return (free(vars->instr), ft_freepipes(vars->pipes), perror("error"),
			errno);
	if (ft_startforking(vars, ft_getcmds(vars, (char **)av), (char **)ev))
		return (free(vars->instr), ft_freepipes(vars->pipes), 0);
	vars->result = ft_readfrompipe(vars);
	ft_putresult(vars->result, av[ac - 1]);
	return (closepipes(vars), 0);
}
