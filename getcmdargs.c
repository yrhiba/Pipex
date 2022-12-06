/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcmdargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:20:54 by yrhiba            #+#    #+#             */
/*   Updated: 2022/12/06 03:02:07 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freepaths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

char	**freertn(char **rtn)
{
	int	i;

	i = 0;
	while (rtn[i])
		free(rtn[i++]);
	return (NULL);
}

char	*getthepath(char *cmd, char **paths)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		return (freepaths(paths), free(cmd), NULL);
	free(cmd);
	cmd = tmp;
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], cmd);
		if (!tmp)
			return (free(cmd), freepaths(paths), NULL);
		if (!(access(tmp, F_OK)))
			return (free(cmd), freepaths(paths), tmp);
		free(tmp);
	}
	return (free(cmd), freepaths(paths), NULL);
}

char	*getcmdpath(char *cmd, const char **ev)
{
	int		i;
	char	**paths;

	i = -1;
	while (ev[++i])
	{
		if (!(ft_strncmp(ev[i], PATH, 5)))
		{
			paths = ft_split((*(ev + i) + 5), ':');
			if (!paths)
				return (free(cmd), NULL);
			break ;
		}
	}
	return (getthepath(cmd, paths));
}

char	**getcmdargs(t_pipex *vars, const char **av, const char **ev, int index)
{
	char	**rtn;

	if (!(ev[0]))
		return (errno = EPROCUNAVAIL, NULL);
	rtn = ft_split(av[index], 32);
	if (!rtn)
		return (NULL);
	rtn[0] = getcmdpath(rtn[0], ev);
	if (!(rtn[0]))
		return (freertn(rtn + 1), free(rtn), NULL);
	return (rtn);
}
