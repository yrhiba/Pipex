/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcmdargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:26:39 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/30 17:42:33 by yrhiba           ###   ########.fr       */
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

char	*ft_getthepath(char *cmd, char **paths)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		return (errno = ENOMEM, freepaths(paths), free(cmd), NULL);
	free(cmd);
	cmd = tmp;
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], cmd);
		if (!tmp)
			return (free(cmd), freepaths(paths), errno = ENOMEM, NULL);
		if (!(access(tmp, F_OK)))
			return (free(cmd), tmp);
		free(tmp);
		i++;
	}
	return (free(cmd), NULL);
}

char	*getcmdpath(char *cmd, char **ev)
{
	int		i;
	char	**paths;

	i = 0;
	while (ev[i])
	{
		if (!(ft_strncmp(ev[i], PATH, 5)))
		{
			paths = ft_split((*(ev + i) + 5), ':');
			if (!paths)
				return (free(cmd), freepaths(paths), errno = ENOMEM, NULL);
			break ;
		}
		i++;
	}
	return (ft_getthepath(cmd, paths));
}

char	**freertn(char **rtn)
{
	int	i;

	i = 0;
	while (rtn[i])
		free(rtn[i++]);
	return (NULL);
}

char	**getcmdargs(t_pipex *vars, char **av, char **ev, int index)
{
	char	**rtn;

	rtn = ft_split(av[index], 32);
	if (!rtn)
		return (NULL);
	rtn[0] = getcmdpath(rtn[0], ev);
	if (!(rtn[0]))
		return (freertn(rtn + 1), free(rtn), NULL);
	return (rtn);
}
