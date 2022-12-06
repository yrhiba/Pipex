/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:42:37 by yrhiba            #+#    #+#             */
/*   Updated: 2022/12/06 03:44:18 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	getcmdscount(t_pipex *vars, int ac, const char **av)
{
	vars->herdoc = 0;
	if (ac > 1 && (strcmp(HERDOC, av[1]) == 0))
		vars->herdoc = 1;
	if (vars->herdoc)
	{
		if (ac < 6)
			return (errno = EIO, -1);
		vars->flags = O_WRONLY | O_CREAT | O_APPEND;
		return (ac - 4);
	}
	if (ac < 5)
		return (errno = EIO, -1);
	vars->flags = O_WRONLY | O_CREAT;
	return (ac - 3);
}

const char	**getcmds(t_pipex *vars, const char **av)
{
	if (vars->herdoc)
		return (av + 3);
	return (av + 2);
}
