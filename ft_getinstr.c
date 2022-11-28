/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 04:21:04 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/28 09:51:52 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_islimtter(char *buff, char *limtter)
{
	while (*buff != '\n' && *buff && *limtter)
	{
		if (*buff != *limtter)
			break ;
		buff++;
		limtter++;
	}
	if (*buff == '\n' && *limtter == '\0')
		return (1);
	return (0);
}

char	*herdoc_getinstr(char *limtter)
{
	char	*rtn;
	char	*buff;
	char	*tmp;

	rtn = ft_strdup("");
	if (!rtn)
		return (errno = ENOMEM, NULL);
	buff = get_next_line(STDIN_FILENO);
	while (buff && !ft_islimtter(buff, limtter))
	{
		tmp = ft_strjoin(rtn, buff);
		free(rtn);
		free(buff);
		if (!tmp)
			return (errno = ENOMEM, NULL);
		rtn = tmp;
		buff = get_next_line(STDIN_FILENO);
	}
	return (free(buff), rtn);
}

char	*file_getinstr(char *path)
{
	int		fd;
	char	*rtn;
	char	*buff;
	char	*tmp;

	rtn = ft_strdup("");
	if (!rtn)
		return (errno = ENOMEM, NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buff = get_next_line(fd);
	while (buff)
	{
		tmp = ft_strjoin(rtn, buff);
		free(buff);
		free(rtn);
		if (!tmp)
			return (errno = ENOMEM, NULL);
		rtn = tmp;
		buff = get_next_line(fd);
	}
	return (rtn);
}

char	*ft_getinstr(int ac, char **av, t_pipex *vars)
{
	int	herdoc;

	herdoc = ft_strcmp(av[1], HERDOC);
	if (herdoc == 0)
	{
		vars->herdoc = 1;
		if (ac < 6)
			return (errno = EIO, NULL);
		return (herdoc_getinstr(av[2]));
	}
	else
	{
		if (ac < 5)
			return (errno = EIO, NULL);
		vars->herdoc = 0;
	}
	return (file_getinstr(av[1]));
}
