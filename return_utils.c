/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:07:56 by yrhiba            #+#    #+#             */
/*   Updated: 2022/12/06 03:34:39 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	rtnfds(t_pipex *vars)
{
	closepipes(vars->pipes);
	freepipes(vars->pipes);
	free(vars);
}

void	rtnforking(t_pipex *vars)
{
	if (vars->herdoc)
	{
		unlink(vars->outfile);
		free(vars->outfile);
	}
	free(vars->fds);
	freepipes(vars->pipes);
	free(vars);
}

void	rtnpipex(t_pipex *vars)
{
	if (vars->herdoc)
	{
		unlink(vars->outfile);
		free(vars->outfile);
	}
	close(vars->fds[0]);
	close(vars->fds[1]);
	free(vars->fds);
	closepipes(vars->pipes);
	freepipes(vars->pipes);
	free(vars);
}

void	closeallfds(t_pipex *vars)
{
	close(vars->fds[0]);
	close(vars->fds[1]);
	closepipes(vars->pipes);
}
