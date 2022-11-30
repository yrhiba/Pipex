/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:13:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/30 17:42:23 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_startforking(t_pipex *vars, char **av, char **ev, int *fds)
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

int	returnthefd(int fd, char *file)
{
	char	*buff;

	buff = get_next_line(fd);
	while (buff)
	{
		write(fd, buff, ft_strlen(buff));
		free(buff);
		buff = get_next_line(fd);
	}
	write(fd, "\0", 1);
	close(fd);
	fd = open(file, O_RDONLY);
	return (fd);
}

int	getfdfromhd(void)
{
	char	*tmpfd;
	char	*tmp;
	int		fd;

	tmpfd = ft_strdup(TMPFD);
	if (!tmpfd)
		return (errno);
	fd = 1;
	while (access(tmpfd, F_OK) != -1)
	{
		tmp = ft_itoa(fd);
		if (!tmp)
			return (-1);
		tmpfd = ft_strjoin(TMPFD, tmp);
		if (!tmpfd)
			return (free(tmp), -1);
		fd++;
	}
	fd = open(tmpfd, O_RDONLY);
	if (fd == -1)
		return (free(tmpfd), free(tmp), -1);
	return (returnthefd(fd, tmpfd));
}

int	*ft_getfds(char **av, t_pipex *vars, int ac)
{
	int	*rtn;

	rtn = (int *)malloc(sizeof(int) * 2);
	if (!rtn)
		return (NULL);
	rtn[1] = open(av[ac - 1], O_WRONLY);
	if (!(vars->herdoc))
	{
		rtn[0] = open(av[1], O_RDONLY);
		if (rtn[0] == -1 || rtn[1] == -1)
			return (free(rtn), NULL);
		return (rtn);
	}
	rtn[0] = getfdfromhd();
	if (rtn[0] == -1 || rtn[1] == -1)
		return (free(rtn), NULL);
	return (rtn);
}

int	main(int ac, char const *av[], char const *ev[])
{
	t_pipex	*vars;
	int		i;

	vars = (t_pipex *)malloc(sizeof(t_pipex));
	if (!vars)
		return (perror("error"), errno);
	vars->cmds_count = ft_getcmdscount(vars->herdoc, ac);
	vars->pipes = ft_getpipes((vars->cmds_count) + 1);
	if (!vars->pipes)
		return (free(vars->instr), perror("error"), errno);
	vars->fds = ft_getfds(av, vars, ac);
	if (!(vars->fds))
		return (free(vars->pipes), free(vars->cmds_count), free(vars),
			perror("error"), errno);
	if (ft_startforking(vars, ft_getcmds(vars, (char **)av), (char **)ev,
			vars->fds))
		return (free(vars->instr), ft_freepipes(vars), errno);
	i = -1;
	while (++i < vars->cmds_count)
		wait(NULL);
	return (closepipes(vars), 0);
}
