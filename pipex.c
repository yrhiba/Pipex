/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:13:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/29 17:06:17 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_writetopipe(t_pipex *vars)
{
	size_t	size;

	size = ft_strlen(vars->instr) + 1;
	if (write(((vars->pipes)[0][1]), vars->instr, (size * sizeof(char))) == -1)
		return (1);
	return (0);
}

char	*ft_readfrompipe(t_pipex *vars)
{
	char	*tmp1;
	char	*tmp2;
	char	*rtn;
	int		fd;

	fd = vars->pipes[vars->cmds_count][0];
	rtn = ft_strdup("");
	if (!rtn)
		return (errno = ENOMEM, NULL);
	tmp1 = get_next_line(fd);
	while (tmp1)
	{
		tmp2 = ft_strjoin(rtn, tmp1);
		free(tmp1);
		free(rtn);
		if (!tmp2)
			return (errno = ENOMEM, NULL);
		tmp1 = get_next_line(fd);
		rtn = tmp2;
	}
	return (rtn);
}

int	ft_startforking(t_pipex *vars, char **av, char **ev)
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
			vars->args = getcmdargs(vars, av, ev, i);
			if (!(vars->args) || execve((vars->args)[0], vars->args, ev) == -1)
				return (free(vars->pids), free(vars->args), perror("error"),
					(vars->error = 1));
			return (1);
		}
		i++;
	}
	return (free(vars->pids), 0);
}

int	ft_putresult(char *result, char *file, int herdoc)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (herdoc)
		flags = flags | O_APPEND;
	fd = open(file, flags);
	if (fd == -1)
		return (-1);
	if (write(fd, result, (ft_strlen(result) + 1)) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char const *av[], char const *ev[])
{
	t_pipex	*vars;

	vars = (t_pipex *)malloc(sizeof(t_pipex));
	if (!vars)
		return (errno = ENOMEM, perror("error"), 0);
	vars->error = 0;
	vars->instr = ft_getinstr(ac, (char **)av, vars);
	if (!(vars->instr))
		return (perror("error"), errno);
	// [projects good]
	vars->cmds_count = ft_getcmdscount(vars->herdoc, ac);
	vars->pipes = ft_getpipes((vars->cmds_count) + 1);
	if (!vars->pipes)
		return (free(vars->instr), perror("error"), errno);
	if (ft_writetopipe(vars))
		return (free(vars->instr), ft_freepipes(vars), perror("error"),
			errno);
	if (ft_startforking(vars, ft_getcmds(vars, (char **)av), (char **)ev))
		return (free(vars->instr), ft_freepipes(vars->pipes), 0);
	// vars->result = ft_readfrompipe(vars);
	// if (!(vars->result))
	// 	return (perror("error"), errno);
	// if (ft_putresult(vars->result, (char *)av[ac - 1], vars->herdoc) == -1)
	// 	return (perror("error"), errno);
	return (closepipes(vars), 0);
}
