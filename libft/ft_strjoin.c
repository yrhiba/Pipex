/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:24:03 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/09 08:39:33 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	char	*tmp;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	rtn = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rtn)
		return (0);
	tmp = rtn;
	i = 0;
	while (s1[i])
		*tmp++ = s1[i++];
	i = 0;
	while (s2[i])
		*tmp++ = s2[i++];
	*tmp = '\0';
	return (rtn);
}
