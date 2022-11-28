/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:13:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/28 08:11:02 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char const *av[], char const *ev[])
{
	t_pipex	*vars;
	char	*instr;

	instr = ft_getinstr(ac, (char **)av);
	if (!instr)
		return (perror("error"), errno);
	return (0);
}
