/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:40:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/12/06 03:43:56 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define HERDOC "here_doc"
# define PATH "PATH="
# define TMPFD ".tempfd"

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	size_t		cmds_count;
	int			**pipes;
	int			*fds;
	int			*pids;
	int			id;
	int			herdoc;
	int			flags;
	const char	**av;
	const char	**ev;
	char		**args;
	char		*outfile;
}				t_pipex;

size_t			getcmdscount(t_pipex *vars, int ac, const char **av);
const char		**getcmds(t_pipex *vars, const char **av);

int				**getpipes(size_t count);
void			closepipes(int **pipes);
int				**freepipes(int **pipes);

int				*getfds(int ac, const char **av, t_pipex *vars);

void			rtnfds(t_pipex *vars);
void			rtnforking(t_pipex *vars);
void			rtnpipex(t_pipex *vars);
void			closeallfds(t_pipex *vars, int *fds);

int				startforking(t_pipex *vars, const char **av, const char **ev,
					int *fds);

char			**getcmdargs(t_pipex *vars, const char **av, const char **ev,
					int index);

#endif
