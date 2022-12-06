/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:13:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/12/06 03:35:16 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char const *av[], char const *ev[])
{
	t_pipex	*vars;

	vars = (t_pipex *)malloc(sizeof(t_pipex));
	if (!vars)
		return (perror("error (vars allocation)"), EXIT_FAILURE);
	vars->cmds_count = getcmdscount(vars, ac, av);
	if ((int)vars->cmds_count == -1)
		return (free(vars), perror("error (getcmdscount)"), EXIT_FAILURE);
	vars->pipes = getpipes((vars->cmds_count) + 1);
	if (!vars->pipes)
		return (free(vars), perror("error (getpipes)"), EXIT_FAILURE);
	vars->fds = getfds(ac, av, vars);
	if (!(vars->fds))
		return (rtnfds(vars), perror("error (getfds)"), EXIT_FAILURE);
	if (startforking(vars, getcmds(vars, av), ev))
		return (rtnforking(vars), EXIT_FAILURE);
	return (rtnpipex(vars), EXIT_SUCCESS);
}
