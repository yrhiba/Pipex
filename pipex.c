/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:13:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/30 20:29:46 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char const *av[], char const *ev[])
{
	t_pipex	*vars;
	int		i;

	vars = (t_pipex *)malloc(sizeof(t_pipex));
	if (!vars)
		return (perror("error"), errno);
	vars->cmds_count = ft_getcmdscount(vars, ac, av);
	vars->pipes = ft_getpipes((vars->cmds_count) + 1);
	if (!vars->pipes)
		return (free(vars->instr), perror("error"), errno);
	vars->fds = ft_getfds((char **)av, vars, ac);
	if (!(vars->fds))
		return (free(vars->pipes), free(vars),
			perror("error"), errno);
	if (startforking(vars, ft_getcmds(vars, (char **)av), (char **)ev,
			vars->fds))
		return (free(vars->instr), ft_freepipes(vars), errno);
	i = -1;
	while (++i < vars->cmds_count)
		wait(NULL);
	return (closepipes(vars), 0);
}
