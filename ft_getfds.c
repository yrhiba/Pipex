/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:45:07 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/30 20:29:29 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	returnthefd(int fd, char *file)
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

static int	getfdfromhd(void)
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
	ft_printf("puts\n");
	rtn[0] = getfdfromhd();
	if (rtn[0] == -1 || rtn[1] == -1)
		return (free(rtn), NULL);
	return (rtn);
}
