/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:10:25 by yrhiba            #+#    #+#             */
/*   Updated: 2022/12/06 03:20:20 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmpherdocdelm(char *buff, const char *delm)
{
	char	*tmp;
	size_t	len;

	if (!buff)
		return (-1);
	len = ft_strlen(buff);
	tmp = ft_strdup(buff);
	if (!tmp)
		return (-1);
	tmp[len - 1] = '\0';
	if (ft_strcmp(tmp, delm) == 0)
		return (free(tmp), 1);
	return (free(tmp), 0);
}

int	puttohdfd(t_pipex *vars, int fd, const char *delm)
{
	char	*buff;
	int		rtncmp;

	buff = get_next_line(STDIN_FILENO);
	rtncmp = cmpherdocdelm(buff, delm);
	while (buff && rtncmp <= 0)
	{
		if (rtncmp == -1)
			return (close(fd), free(buff), -1);
		if (write(fd, buff, ft_strlen(buff)) == -1)
			return (close(fd), free(buff), free(vars->outfile), -1);
		free(buff);
		buff = get_next_line(STDIN_FILENO);
		rtncmp = cmpherdocdelm(buff, delm);
	}
	close(fd);
	fd = open(vars->outfile, O_RDONLY);
	if (fd == -1)
		return (free(vars->outfile), -1);
	return (fd);
}

int	getfdfromhd(const char **av, t_pipex *vars)
{
	char	*path;
	char	*tmp;
	int		fd;

	fd = 1;
	path = ft_strdup(TMPFD);
	if (!path)
		return (-1);
	while (access(path, F_OK) == 0)
	{
		free(path);
		tmp = ft_itoa(fd);
		if (!tmp)
			return (-1);
		path = ft_strjoin(TMPFD, tmp);
		free(tmp);
		if (!path)
			return (-1);
		fd++;
	}
	fd = open(path, O_CREAT | O_WRONLY, 0777);
	if (fd == -1)
		return (free(path), -1);
	vars->outfile = path;
	return (puttohdfd(vars, fd, av[2]));
}

int	*getfds(int ac, const char **av, t_pipex *vars)
{
	int	*rtn;

	rtn = (int *)malloc(sizeof(int) * 2);
	if (!rtn)
		return (NULL);
	if (!(vars->herdoc))
		unlink(av[ac - 1]);
	rtn[1] = open(av[ac - 1], (vars->flags), 0644);
	if (rtn[1] == -1)
		return (perror("error 88(getfds)"), free(rtn), NULL);
	if (vars->herdoc)
	{
		rtn[0] = getfdfromhd(av, vars);
		if (rtn[0] == -1)
			return (perror("error 94(getfds)"), close(rtn[1]), free(rtn), NULL);
		return (rtn);
	}
	rtn[0] = open(av[1], O_RDONLY);
	if (rtn[0] == -1)
		return (perror("error 98(getfds)"), close(rtn[1]), free(rtn), NULL);
	return (rtn);
}
