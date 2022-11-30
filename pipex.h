/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:40:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/30 17:45:41 by yrhiba           ###   ########.fr       */
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
	size_t	cmds_count;
	int		**pipes;
	int		*fds;
	int		*pids;
	int		id;
	int		herdoc;
	int		error;
	char	*instr;
	char	*result;
	char	**args;
}			t_pipex;

char		*ft_getinstr(int ac, char **av, t_pipex *vars);
int			**ft_getpipes(int count);
size_t		ft_getcmdscount(int herdoc, int ac);
char		**ft_getcmds(t_pipex *vars, char **av);
int			**ft_freepipes(t_pipex *vars);
void		closepipes(t_pipex *vars);
char		**getcmdargs(t_pipex *vars, char **av, char **ev, int index);
int			*ft_getfds(char **av, t_pipex *vars, int ac);

#endif
